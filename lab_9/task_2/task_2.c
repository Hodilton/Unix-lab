#include "task_2.h"

typedef struct {
    double number;
    int index;
} client_arg_t;

typedef struct {
    double sum;
    int count;
    pthread_mutex_t mutex;
} shared_data_t;

shared_data_t shared_data = {0.0, 0, PTHREAD_MUTEX_INITIALIZER};
int running = 1;

void* server_2() {
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
    address.sin_port = htons(PORT_2);

    if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return NULL;
    }
    while (running) {
        int recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&address, &addrlen);
        if (recv_len < 0) {
            perror("recvfrom failed");
            continue;
        }
        buffer[recv_len] = '\0';
                double received_number = atof(buffer);
        pthread_mutex_lock(&shared_data.mutex);
        shared_data.sum += received_number;
        shared_data.count++;
        pthread_mutex_unlock(&shared_data.mutex);
        char response[BUFFER_SIZE];
        sprintf(response, "Received number: %.2f\n", received_number);
        sendto(sockfd, response, strlen(response), 0, (struct sockaddr*)&address, addrlen);
    }

    close(sockfd);
    return NULL;
}

void* client_2(void* arg) {
    client_arg_t* client_data = (client_arg_t*)arg;
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_2);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    sprintf(buffer, "%.2f", client_data->number);
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    socklen_t addr_len = sizeof(serv_addr);
    int recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&serv_addr, &addr_len);
    buffer[recv_len] = '\0';
    printf("Client %d received:\n%s\n", client_data->index, buffer);

    close(sockfd);
    free(client_data);
    return NULL;
}

void task_2() {
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, server_2, NULL);
    usleep(100000);

    const int n = 5;
    pthread_t client_threads[n];

    for (int i = 0; i < n; i++) {
        client_arg_t* client_data = malloc(sizeof(client_arg_t));
        client_data->number = exp(i + 1);
        client_data->index = i + 1;
        pthread_create(&client_threads[i], NULL, client_2, client_data);
        usleep(100000);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(client_threads[i], NULL);
    }
    running = 0;
    usleep(100000);
    pthread_mutex_lock(&shared_data.mutex);
    if (shared_data.count > 0) {
        double average = shared_data.sum / shared_data.count;
        printf("Average value: %.2f\n", average);
    } else {
        printf("No numbers received.\n");
    }
    pthread_mutex_unlock(&shared_data.mutex);

    pthread_join(server_thread, NULL);
}