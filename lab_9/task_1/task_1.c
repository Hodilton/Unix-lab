#include "task_1.h"

typedef struct {
    char message[BUFFER_SIZE];
    int index;
} client_arg_t;

void *server_1() {
    int sockfd;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT_1);

    if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return NULL;
    }

    while (1) {
        int recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&address, &addrlen);
        if (recv_len < 0) {
            perror("recvfrom failed");
            continue;
        }
        buffer[recv_len] = '\0'; // Завершаем строку

        // Отправка длины сообщения
        char response[BUFFER_SIZE];
        sprintf(response, "Length of message: %d", recv_len);
        sendto(sockfd, response, strlen(response), 0, (struct sockaddr*)&address, addrlen);
    }

    close(sockfd);
    return NULL;
}

void *client_1(void *arg) {
    client_arg_t *client_data = (client_arg_t *)arg;
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_1);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    sendto(sockfd, client_data->message, strlen(client_data->message), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    socklen_t addr_len = sizeof(serv_addr);
    int recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&serv_addr, &addr_len);
    buffer[recv_len] = '\0';
    printf("Client %d received.\n%s\n", client_data->index, buffer);

    close(sockfd);
    free(client_data); // Освобождаем выделенную память
    return NULL;
}

void task_1() {
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, server_1, NULL);
    usleep(100000);

    const int n = 3;
    pthread_t client_threads[n];

    for (int i = 0; i < n; i++) {
        client_arg_t *client_data = malloc(sizeof(client_arg_t));
        switch (i) {
            case 0:
                strcpy(client_data->message, "Hello, world!");
                break;
            case 1:
                strcpy(client_data->message, "Hello");
                break;
            case 2:
                strcpy(client_data->message, "I'm a client");
                break;
        }
        client_data->index = i + 1;
        pthread_create(&client_threads[i], NULL, client_1, client_data);
        usleep(100000);
    }

    for (int i = 0; i < n; i++) pthread_join(client_threads[i], NULL);

    pthread_cancel(server_thread);
    pthread_join(server_thread, NULL);
}