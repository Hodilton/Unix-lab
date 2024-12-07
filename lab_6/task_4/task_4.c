#include "task_4.h"

void task_4() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Ошибка fork()");
        return;
    }

    if (pid > 0) {
        // Родительский процесс
        printf("PID дочернего процесса: %d\n", pid);
    } else {
        // Дочерний процесс
        printf("Дочерний процесс работает\n");
        _exit(0);
    }
}