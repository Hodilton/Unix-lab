#include "task_5.h"

void task_5() {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Ошибка открытия файла");
        return;
    }

    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Ошибка fork()");
        close(fd);
        return;
    }

    if (pid > 0) { // Родительский процесс
        char buffer[128];
        ssize_t bytesRead = read(fd, buffer, sizeof(buffer));

        if (bytesRead == -1) {
            perror("Ошибка чтения файла");
        } else {
            buffer[bytesRead] = '\0';
            printf("Содержимое файла: %s\n", buffer);
        }

        close(fd);
    } else { // Дочерний процесс
        execl("/bin/ls", "ls", NULL);
        perror("Ошибка exec()");
    }
}