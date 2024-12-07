#include "task_5.h"

struct message {
    long type;
    char text[SIZE];
};

void send() {
    key_t key = ftok("../task_5/task_5.c", 65);
    if (key == -1) {
        perror("Error generating key");
        exit(1);
    }

    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Error creating message queue");
        exit(1);
    }

    struct message msg;
    printf("Enter message: ");
    fgets(msg.text, SIZE, stdin);
    msg.type = 1;

    if (msgsnd(msgid, &msg, sizeof(msg), 0) == -1) {
        perror("Error sending message");
        exit(1);
    }
}

void receive() {
    key_t key = ftok("../task_5/task_5.c", 65);
    if (key == -1) {
        perror("Error generating key");
        exit(1);
    }
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Error creating message queue");
        exit(1);
    }
    struct message msg;
    if (msgrcv(msgid, &msg, sizeof(msg), 1, 0) == -1) {
        perror("Error receiving message");
        exit(1);
    }
    printf("Received message: %s\n", msg.text);
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("Error removing message queue");
        exit(1);
    }
}

void task_5() {
    send();
    receive();
}