#include "task_4.h"

const int size = 100;

void task_4() {
    int shmid = shmget(IPC_PRIVATE, size, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Failed to create shared memory");
        return 1;
    }
    char* data = (char*)shmat(shmid, NULL, 0);
    if (data == (char*)(-1)) {
        perror("Failed to attach shared memory");
        return 1;
    }
    int pid = fork();
    if (pid < 0) {
        perror("Failed to fork");
        return 1;
    }
    else if (pid == 0) {
        usleep(100000);
        printf("Received message: %s\n", data);
        shmdt(data);
        exit(0);
    }
    else {
        sprintf(data, "PID of sender: %d.", getpid());
        printf("Sended message: %s\n", data);
        fgets(data, size, stdin);
        wait(NULL);
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }
}