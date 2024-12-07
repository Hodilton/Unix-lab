#include "task_2.h"
#include "input.h"
#include <stdio.h>
#include <math.h>

unsigned long long fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    unsigned long long a = 0, b = 1, fib;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

double find_limit(double precision) {
    int n = 2; // Начальное значение
    double prev_ratio = 0.0, current_ratio;
    
    do {
        unsigned long long fib_n = fibonacci(n);
        unsigned long long fib_n_1 = fibonacci(n - 1);    
        current_ratio = (double)fib_n / fib_n_1;
        
        if (fabs(current_ratio - prev_ratio) < precision) {
            break;
        }
        
        prev_ratio = current_ratio;
        n++;     
    } while (1); 
    return current_ratio;
}

void task_2() {
    double precision;
    precision = getDouble("Введите погрешность для вычисления предела: ", 0, 0, 1, 1);
    double golden_ratio = find_limit(precision);
    printf("Предел отношения двух последовательных чисел ряда Фибоначчи с заданной точностью: %.10lf\n", golden_ratio);
}