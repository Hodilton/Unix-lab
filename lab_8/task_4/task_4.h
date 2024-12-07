#ifndef TASK_4_H
#define TASK_4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>

#define PORT_2 8073
#define BUFFER_SIZE 256

void task_4();

#endif