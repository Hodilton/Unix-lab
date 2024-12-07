#include "task_2.h"

const char* message = "HELLO, WORLD!";

void task_2() {
    printf("Original message: %s\n", message);
    int fd[2];

    pipe(fd);
    write(fd[1], message, strlen(message) + 1);
    close(fd[1]);

    if (fork() == 0) {
        char message[100];
        close(fd[1]);
        read(fd[0], message, sizeof(message));

        for (int i = 0; message[i]; i++) {
            message[i] = tolower(message[i]);
        }
        printf("Changed message: %s\n", message);

        close(fd[0]);
        exit(0);
    }

    close(fd[0]);
    wait(NULL);
}