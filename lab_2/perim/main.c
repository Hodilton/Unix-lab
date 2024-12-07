#include <stdio.h>
#include "input.h"

int main(void) {
    float a1;
    float result;

    a1 = getFloat("Введите длину стороны квадрата: ", 0, 0);

    if(a1 == 0) {
        return 0;
    }

    result = a1 * 4;
    printf("Периметр: %6.2f\n", result);

    return 0;
}