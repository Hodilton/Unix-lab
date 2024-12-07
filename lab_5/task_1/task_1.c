#include "task_1.h"
#include "input.h"
#include <stdio.h>
#include <time.h>

void decimal_to_base(double number, int base) {
    int integer_part = (int)number;
    double fractional_part = number - integer_part;
    char result[32];
    int i = 0;

    while (integer_part > 0) {
        int remainder = integer_part % base;
        result[i++] = (remainder > 9) ? (remainder - 10) + 'A' : remainder + '0';
        integer_part /= base;
    }
    result[i] = '\0';

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }

    if (fractional_part > 0) {
        printf(".");
        int count = 0;
        while (fractional_part > 0 && count < 10) { // Ограничение для точности
            fractional_part *= base;
            int int_part = (int)fractional_part;
            printf("%c", (int_part > 9) ? (int_part - 10) + 'A' : int_part + '0');
            fractional_part -= int_part;
            count++;
        }
    }
    printf("\n");
}


void task_1() {
    double number = getDouble("Введите число: ", 0, 0, 1, 1);
    int base = getInt("Введите основание", 1, 17, 0, 0);
    decimal_to_base(number, base);
}