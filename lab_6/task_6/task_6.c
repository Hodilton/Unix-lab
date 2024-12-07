#include "task_6.h"

void task_6(void) {
    pid_t pid1, pid2;
    
    pid1 = fork();
    if (pid1 == -1) {
        perror("Ошибка fork() для процесса 1");
        return;
    }

    if (pid1 == 0) { // Дочерний процесс 1
        printf("Процесс 1\n");
        return;
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("Ошибка fork() для процесса 2");
        return;
    }

    if (pid2 == 0) { // Дочерний процесс 2
        printf("Процесс 2\n");
        return;
    }

    // Родительский процесс
    wait(NULL);  // Ожидаем завершения дочернего процесса 1
    wait(NULL);  // Ожидаем завершения дочернего процесса 2
    printf("Оба процесса завершены.\n");
}