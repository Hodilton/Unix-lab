#include <stdio.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include "calculate_edit.h"

float Calculate(float Numeral, const char *Operation) {
    float SecondNumeral;

    if (strncmp(Operation, "+", 1) == 0) {
        printf("Введите второе слагаемое: ");
        (void)scanf("%f", &SecondNumeral);  // Игнорируем рузельтат
        return Numeral + SecondNumeral;
    }
    else if (strncmp(Operation, "-", 1) == 0) {
        printf("Введите вычитаемое: ");
        (void)scanf("%f", &SecondNumeral);  // Игнорируем рузельтат
        return Numeral - SecondNumeral;
    }
    else if (strncmp(Operation, "*", 1) == 0) {
        printf("Введите множитель: ");
        (void)scanf("%f", &SecondNumeral);  // Игнорируем результат
        return Numeral * SecondNumeral;
    }
    else if (strncmp(Operation, "/", 1) == 0) {
        printf("Введите делитель: ");
        (void)scanf("%f", &SecondNumeral);  // Игнорируем результат
        if (fabs(SecondNumeral) < FLT_EPSILON) {  // Сравниваем с плавающей точкой
            printf("Ошибка: деление на ноль!\n");
            return (float)HUGE_VAL;
        }
        return Numeral / SecondNumeral;
    }
    else if (strncmp(Operation, "pow", 3) == 0) {
        printf("Введите степень: ");
        (void)scanf("%f", &SecondNumeral);  // Игнорируем результат
        return (float)pow(Numeral, SecondNumeral);  // Приводим к float
    }
    else if (strncmp(Operation, "sqrt", 4) == 0) {
        return (float)sqrt(Numeral);  // Приводим к float
    }
    else if (strncmp(Operation, "sin", 3) == 0) {
        return (float)sin(Numeral);  // Приводим к float
    }
    else if (strncmp(Operation, "cos", 3) == 0) {
        return (float)cos(Numeral);  // Приводим к float
    }
    else if (strncmp(Operation, "tan", 3) == 0) {
        return (float)tan(Numeral);  // Приводим к float
    }
    else {
        printf("Неправильно введено действие\n");
        return (float)HUGE_VAL;
    }
}