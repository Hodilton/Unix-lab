#include "task_4.h"
#include "input.h"

#include <stdio.h>
#include <math.h>

int f1(float x, float y) {
    return (x >= -3 && x <= 3 && 
            y >= -5 && y <= 5 && 
            (fabs(x) + fabs(y)) <= 5);
}

int f2(float x, float y) {
    return (y <= 5 / 3.0 * x + 5
            && y <= -5 / 3.0 * x + 5
            && x >= -3 && x <= 3 && y >= 0);
}

int f3(float x, float y) {
    return (x * x + y * y <= 16);
}

int f4(float x, float y) {
    return (x * x + y * y <= 16 && x >= 0 && x * x + y * y >= 4);
}

int f5(float x, float y) {
    return ((x >= -4 && x <= 4 && y >= -1 && y <= 2)
            || (x >= -2 && x <= 2 && y <= -1 && y >= -5));
}

void task_4() {
    float x = getFloat("Введите x: ", 0, 0, 1, 1);
    float y = getFloat("Введите y: ", 0, 0, 1, 1);

    if (f1(x, y)) {
        printf("Точка (%.2f, %.2f) принадлежит области на рис.1.\n", x, y);
    } else {
        printf("Точка (%.2f, %.2f) не принадлежит области на рис.1.\n", x, y);
    }

    if (f2(x, y)) {
        printf("Точка (%.2f, %.2f) принадлежит области на рис.2.\n", x, y);
    } else {
        printf("Точка (%.2f, %.2f) не принадлежит области на рис.2.\n", x, y);
    }

    if (f3(x, y)) {
        printf("Точка (%.2f, %.2f) принадлежит области на рис.3.\n", x, y);
    } else {
        printf("Точка (%.2f, %.2f) не принадлежит области на рис.3.\n", x, y);
    }

    if (f4(x, y)) {
        printf("Точка (%.2f, %.2f) принадлежит области на рис.4.\n", x, y);
    } else {
        printf("Точка (%.2f, %.2f) не принадлежит области на рис.4.\n", x, y);
    }

    if (f5(x, y)) {
        printf("Точка (%.2f, %.2f) принадлежит области на рис.5.\n", x, y);
    } else {
        printf("Точка (%.2f, %.2f) не принадлежит области на рис.5.\n", x, y);
    }
}
