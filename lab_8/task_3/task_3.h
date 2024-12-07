#ifndef TASK_3_H
#define TASK_3_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>

#define PORT_3 8083
#define BUFFER_SIZE 1024

void *server_3(void *arg);
void client_3();
void task_3();

#endif