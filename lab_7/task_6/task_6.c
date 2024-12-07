#include "task_6.h"

void task_6(void) {
    sem_t *sem = sem_open("/example_sem", O_CREAT, 0644, 0);
    double *shared_result = mmap(NULL, sizeof(double), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (fork() == 0) {
        double x = 0;
        
        printf("Process №%d is calculating...\n", getpid());

        for(int i = 1; i < INT_MAX; i++) {
            x += 1.0 / i;
        }

        *shared_result = x;

        sem_post(sem);
        exit(0);
    }
    else {
        sem_wait(sem);
        printf("Result of calculations: %lf\n", *shared_result);
        wait(NULL);
    }
    sem_close(sem);
    sem_unlink("/example_sem");
}