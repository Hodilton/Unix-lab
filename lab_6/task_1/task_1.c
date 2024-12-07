#include "task_1.h"

void task_1() {
    int fd;
    char buffer[128];
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Ошибка открытия файла");
        return;
    }

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