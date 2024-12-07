#include "task_semaphore.h"

sem_t semaphore;
FILE* file;

volatile int completed_writes = 0;

void* writer_semaphore(void* arg) {
    for (int i = 0; i < 5; i++) {
        sem_wait(&semaphore);

        fprintf(file, "Data %d\n", i);
        fflush(file);
        printf("Write: Data %d\n", i);

        completed_writes++;

        sem_post(&semaphore);
        usleep(100000);
    }
    return NULL;
}

void* reader_semaphore(void* arg) {
    char buffer[100];
    int last_read = 0;

    while (last_read < 5) {
        sem_wait(&semaphore);

        fseek(file, 0, SEEK_SET);

        int current_read = 0;
        int found_data = 0;
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            if (current_read >= last_read) {
                printf("Read: %s", buffer);
                found_data = 1;
            }
            current_read++;
        }
        
        last_read = current_read;

        if (found_data) {
            printf("\n");
        }

        sem_post(&semaphore);
        usleep(100000);
    }
    return NULL;
}


void print_file_content() {
    FILE* output = fopen("file.txt", "r");

    if (output == NULL) {
        perror("Failed to open file for reading");
        return;
    }
    
    printf("Final file content:\n");

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), output) != NULL) {
        printf("%s", buffer);
    }

    fclose(output);
}


void task_semaphore() {
    pthread_t thread1, thread2;

    file = fopen("file.txt", "w+");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    sem_init(&semaphore, 0, 1);

    pthread_create(&thread1, NULL, writer_semaphore, NULL);
    pthread_create(&thread2, NULL, reader_semaphore, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&semaphore);
    fclose(file);

    print_file_content();

}