#include "task_1.h"

void *server_1(void *arg) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT_1);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return NULL;
    }
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return NULL;
    }

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

        if (new_socket < 0) {
            perror("Accept failed");
            return NULL;
        }
        
        char buffer[BUFFER_SIZE] = {0};
        recv(new_socket, buffer, BUFFER_SIZE, 0);
        char response[BUFFER_SIZE];
        sprintf(response, "Character count: %ld", strlen(buffer));
        send(new_socket, response, strlen(response), 0);
        close(new_socket);
    }

    close(server_fd);
    return NULL;
}

void client_1() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char input[BUFFER_SIZE], response[BUFFER_SIZE];
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_1);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    printf("Enter a string: ");
    scanf("%s", input);
    send(sock, input, strlen(input), 0);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server Response: %s\n", response);
    close(sock);
}

void task_1() {
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, server_1, NULL);
    usleep(100000); // Даем серверу время запуститься
    client_1();
    pthread_cancel(server_thread); // Завершаем сервер
    pthread_join(server_thread, NULL);
}