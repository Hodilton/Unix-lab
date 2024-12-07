#include "task_3.h"

void task_3() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) { // Первый дочерний процесс
        char message[100];
        sprintf(message, "PID of sender: %d", getpid()); // Формируем сообщение с PID
        close(fd[0]); // Закрываем входной конец
        write(fd[1], message, strlen(message) + 1); // Записываем сообщение
        close(fd[1]); // Закрываем выходной конец
        exit(0);
    }

    usleep(100000);

    if (fork() == 0) {
        char buffer[100];
        close(fd[1]); // Закрываем выходной конец
        read(fd[0], buffer, sizeof(buffer)); // Читаем сообщение
        printf("Received message: %s\n", buffer);
        close(fd[0]);
        exit(0);
    }
    
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
}