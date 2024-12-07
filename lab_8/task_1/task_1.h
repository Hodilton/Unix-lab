#ifndef TASK_1_H
#define TASK_1_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>

#define PORT_1 8081
#define BUFFER_SIZE 1024

void *server_1(void *arg);
void client_1();
void task_1();

#endif