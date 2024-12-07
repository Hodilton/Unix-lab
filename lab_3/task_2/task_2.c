#include "task_2.h"
#include "input.h"
#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void calculateDayOfYear(int day, int month, int year) {
    int daysInMonths[] = { 31, isLeapYear(year) 
                                ? 29 
                                : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int dayOfYear = 0;

    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonths[i];
    }

    dayOfYear += day;

    printf("Порядковый номер дня: %d\n", dayOfYear);
}

void task_2() {
    int day = getInt("Введите день: ", 0, 32, 0, 0);
    int month = getInt("Введите месяц: ", 0, 13, 0, 0);
    int year = getInt("Введите год: ", 0, 0, 0, 1);

    calculateDayOfYear(day, month, year);
}