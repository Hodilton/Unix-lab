#include "task_1.h"
#include "input.h"

#include <stdio.h>
#include <time.h>

void processAge(int age) {
    // Возраст
    if (age % 10 == 1 && age != 11) {
        printf("Ваш возраст %d год\n", age);
    } else if ((age % 10 >= 2 && age % 10 <= 4) && !(age >= 12 && age <= 14)) {
        printf("Ваш возраст %d года\n", age);
    } else {
        printf("Ваш возраст %d лет\n", age);
    }

    // Совершеннолетие
    if (age < 18) {
        printf("Вам до совершеннолетия %d лет\n", 18 - age);
    } else if (age == 18) {
        printf("Вы совершеннолетний\n");
    } else {
        printf("Вы совершеннолетний %d лет\n", age - 18);
    }

    // Пенсия
    if (age < 60) {
        printf("Вам до пенсии %d лет\n", 60 - age);
    } else if (age == 60) {
        printf("Вы пенсионер\n");
    } else {
        printf("Вы на пенсии %d лет\n", age - 60);
    }
}

void task_1() {
    int age;
    age = getInt("Введите возраст: ", 0, 0, 0, 1);
    processAge(age);
}