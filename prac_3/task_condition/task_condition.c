#include "task_condition.h"

pthread_mutex_t mutex;
pthread_cond_t cond;

int buffer = 0;
int full = 0;

void* writer_condition(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);

        while (full == 1) {
            pthread_cond_wait(&cond, &mutex);
        }

        buffer = i;
        printf("Write buffer: %d\n", buffer);

        full = 1;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* reader_condition(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);

        while (full == 0) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("Read buffer: %d\n", buffer);
        
        full = 0;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void task_condition() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&thread1, NULL, writer_condition, NULL);
    pthread_create(&thread2, NULL, reader_condition, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}