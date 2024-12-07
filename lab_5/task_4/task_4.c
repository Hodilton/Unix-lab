#include "task_4.h"
#include "input.h"
#include "task_1.h"

#include <stdio.h>
#include <math.h>


void task_4() {
    int N = 0xFF - 0xD3;

    printf("Результат в десятичной системе:" );
    decimal_to_base(N, 10);

    return;
}