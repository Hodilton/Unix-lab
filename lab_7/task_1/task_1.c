#include "task_1.h"

#define NAME "myfifo"

int write_1() {
    char buffer[100];
    mkfifo(NAME, 0666);

    printf("Enter a message: ");
    fgets(buffer, sizeof(buffer), stdin);

    int fd = open(NAME, O_WRONLY);

    write(fd, buffer, sizeof(buffer));
    close(fd);

    return 0;
}

int read_1() {
    char buffer[100];

    if (access(NAME, F_OK) == -1) {
        perror("FIFO doesn't exist");
        return 1;
    }

    int fd = open(NAME, O_RDONLY);
    
    read(fd, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);
    close(fd);
    unlink(NAME);

    return 0;
}

void task_1() {
    int writer = write_1();
    if (writer > 0) return 1;

    int reader = read_1();
    if (reader > 0) return 1;
}