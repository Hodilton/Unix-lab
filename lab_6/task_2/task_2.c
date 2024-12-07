#include "task_2.h"

void task_2() {
    int fd;
    const char *message = "Привет, Linux!";
    
    fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Ошибка создания файла");
        return;
    }

    ssize_t bytesWritten = write(fd, message, strlen(message));
    if (bytesWritten == -1) {
        perror("Ошибка записи в файл");
        close(fd);
        return;
    }

    close(fd);

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Ошибка открытия файла для чтения");
        return;
    }

    char buffer[128];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("Ошибка чтения файла");
        close(fd);
        return;
    }

    buffer[bytesRead] = '\0';
    printf("Содержимое файла: %s\n", buffer);

    close(fd);
}