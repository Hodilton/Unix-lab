#include "input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

int getInt(const char* prompt, int min, int max, int useMinBound, int useMaxBound) {
    if (useMinBound) min = INT_MIN;
    if (useMaxBound) max = INT_MAX;

    int input;
    int status;
    char ch;

    do {
        printf("%s (", prompt);
        if (useMinBound) {
            printf("мин");
        } else {
            printf("%d", min);
        }
        printf(", ");
        if (useMaxBound) {
            printf("макс");
        } else {
            printf("%d", max);
        }
        printf("): ");
        
        status = scanf("%d", &input);

        if (status == 1) {
            if (input < min || input > max) {
                printf("Ошибка: значение вне диапазона.\n");
                status = 0;
            } else if ((ch = getchar()) != '\n') {
                printf("Ошибка: введены некорректные символы.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                status = 0;
            }
        } else {
            printf("Ошибка: введено не число.\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    } while (status != 1);

    return input;
}

float getFloat(const char* prompt, float min, float max, int useMinBound, int useMaxBound) {
    if (useMinBound) min = -FLT_MAX;
    if (useMaxBound) max = FLT_MAX;

    float input;
    int status;
    char ch;

    do {
        printf("%s (", prompt);
        if (useMinBound) {
            printf("мин");
        } else {
            printf("%.2f", min);
        }
        printf(", ");
        if (useMaxBound) {
            printf("макс");
        } else {
            printf("%.2f", max);
        }
        printf("): ");
        
        status = scanf("%f", &input);

        if (status == 1) {
            if (input < min || input > max) {
                printf("Ошибка: значение вне диапазона.\n");
                status = 0;
            } else if ((ch = getchar()) != '\n') {
                printf("Ошибка: введены некорректные символы.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                status = 0;
            }
        } else {
            printf("Ошибка: введено не число.\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    } while (status != 1);

    return input;
}

double getDouble(const char* prompt, double min, double max, int useMinBound, int useMaxBound) {
    if (useMinBound) min = -DBL_MAX;
    if (useMaxBound) max = DBL_MAX;

    double input;
    int status;
    char ch;

    do {
        printf("%s (", prompt);
        if (useMinBound) {
            printf("мин");
        } else {
            printf("%.2f", min);
        }
        printf(", ");
        if (useMaxBound) {
            printf("макс");
        } else {
            printf("%.2f", max);
        }
        printf("): ");
        
        status = scanf("%lf", &input);

        if (status == 1) {
            if (input < min || input > max) {
                printf("Ошибка: значение вне диапазона.\n");
                status = 0;
            } else if ((ch = getchar()) != '\n') {
                printf("Ошибка: введены некорректные символы.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                status = 0;
            }
        } else {
            printf("Ошибка: введено не число.\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    } while (status != 1);

    return input;
}

void getString(const char* prompt, char* buffer, int maxLength) {
    printf("%s (макс. длина %d): ", prompt, maxLength);
    fgets(buffer, maxLength, stdin);

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

void getIntArray(const char* prompt, int* array, int size) {
    char buffer[1024];
    printf("%s (введите %d чисел через пробел):\n", prompt, size);

    getString(prompt, buffer, sizeof(buffer));

    char* token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL && i < size) {
        int num;
        if (sscanf(token, "%d", &num) == 1) {
            array[i++] = num;
        } else {
            printf("Ошибка: некорректный ввод числа.\n");
            break;
        }
        token = strtok(NULL, " ");
    }

    if (i < size) {
        printf("Ошибка: введено недостаточно чисел.\n");
    }
}

void getFloatArray(const char* prompt, float* array, int size) {
    char buffer[1024];
    getString(prompt, buffer, sizeof(buffer));

    char* token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL && i < size) {
        float num;
        if (sscanf(token, "%f", &num) == 1) {
            array[i++] = num;
        } else {
            printf("Ошибка: некорректный ввод числа.\n");
            break;
        }
        token = strtok(NULL, " ");
    }

    if (i < size) {
        printf("Ошибка: введено недостаточно чисел.\n");
    }
}
