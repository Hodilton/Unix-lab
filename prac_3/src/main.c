#include "task_mutex.h"
#include "task_semaphore.h"
#include "task_condition.h"

int main() {
    printf("Task 1: Mutex\n");
    task_mutex();

    printf("\nTask 2: Semaphore\n");
    task_semaphore();

    printf("\nTask 3: Condition\n");
    task_condition();

    return 0;
}