#include "task_3.h"

void task_3(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fd = open(filename, O_CREAT | O_WRONLY, 0644);

        if (fd == -1) {
            perror("Ошибка создания файла");
            return;
        }

        const char *error_msg = "Ошибка: файл не существует";
        write(fd, error_msg, strlen(error_msg));
        close(fd);
        return;
    }

    char buffer[64];
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