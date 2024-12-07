#include "task_mutex.h"

pthread_mutex_t lock;
int shared_variable = 0;

void* increment_by_one(void* arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&lock);
        shared_variable++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* increment_by_two(void* arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&lock);
        shared_variable += 2;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void task_mutex() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, increment_by_one, NULL);
    pthread_create(&thread2, NULL, increment_by_two, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Shared Variable: %d\n", shared_variable);

    pthread_mutex_destroy(&lock);
}