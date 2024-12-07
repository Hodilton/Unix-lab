#include "task_1.h"

#include <stdio.h>
#include <time.h>

void displayCurrentTime() {
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    printf("Текущее время: %02d:%02d:%02d\n",
                            localTime->tm_hour,
                            localTime->tm_min,
                            localTime->tm_sec);
}

void task_1() {
    displayCurrentTime();
}