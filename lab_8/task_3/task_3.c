#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>

#include "task_3.h"

#define PORT_3 8083
#define BUFFER_SIZE 1024

void *server_3(void *arg) {
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
    address.sin_port = htons(PORT_3);

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

        int a, b;
        char op;
        char response[BUFFER_SIZE];

        if (sscanf(buffer, "%d %c %d", &a, &op, &b) != 3) {
            snprintf(response, BUFFER_SIZE, "Invalid operation");
        } else {
            int result = 0;
            int valid = 1;

            switch (op) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        snprintf(response, BUFFER_SIZE, "Division by zero");
                        valid = 0;
                    } else {
                        result = a / b;
                    }
                    break;
                default:
                    valid = 0;
                    snprintf(response, BUFFER_SIZE, "Unsupported operator");
                    break;
            }

            if (valid) {
                snprintf(response, BUFFER_SIZE, "Result: %d", result);
            }
        }

        response[BUFFER_SIZE - 1] = '\0'; // Гарантируем завершение строки
        send(new_socket, response, strlen(response) + 1, 0); // Отправляем с завершающим символом
        close(new_socket);
    }

    close(server_fd);
    return NULL;
}

void client_3() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char expression[BUFFER_SIZE], response[BUFFER_SIZE] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_3);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    printf("Enter a simple mathematical expression: ");
    fgets(expression, BUFFER_SIZE, stdin);

    // Удаляем символ '\n', если он есть
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    send(sock, expression, strlen(expression), 0);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server Response: %s\n", response);
    close(sock);
}

void task_3() {
    pthread_t server_thread;

    // Запускаем поток с сервером server_3
    pthread_create(&server_thread, NULL, server_3, NULL);

    // Даем серверу время на запуск
    usleep(100000);
    client_3();

    // Завершаем серверный поток
    pthread_cancel(server_thread);
    pthread_join(server_thread, NULL);
}