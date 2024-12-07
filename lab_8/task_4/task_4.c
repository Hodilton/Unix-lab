#include "task_4.h"

void *server_4(void *arg) {
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
    address.sin_port = htons(PORT_2);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return NULL;
    }
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return NULL;
    }
    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("Accept failed");
        return NULL;
    }
    char file_name[BUFFER_SIZE] = {0}, response[BUFFER_SIZE];
    recv(new_socket, file_name, BUFFER_SIZE, 0);
    int file = open(file_name, O_RDONLY);
    if (file >= 0) {
        close(file);
        strcpy(response, "This file exists.");
    }
    else {
        strcpy(response, "This file doesn't exist.");
    }
    send(new_socket, response, strlen(response), 0);
    close(new_socket);
    close(server_fd);
    return NULL;
}
void client_4() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char name[BUFFER_SIZE], response[BUFFER_SIZE];
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_2);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    printf("Enter a name of file: ");
    scanf("%s", name);
    send(sock, name, strlen(name), 0);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server Response: %s\n", response); // Выводим ответ сервера
    close(sock);
}

void task_4() {
    pthread_t server_thread;
    usleep(100000);
    pthread_create(&server_thread, NULL, server_4, NULL);
    usleep(100000);
    client_4();
    pthread_join(server_thread, NULL);
}