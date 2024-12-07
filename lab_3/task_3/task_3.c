#include "task_3.h"
#include "input.h"

#include <stdio.h>
#include <math.h>

void solveQuadraticEquation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("Уравнение не имеет действительных корней.\n");
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("Один корень: %.2f\n", root);
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Два корня: %.2f и %.2f\n", root1, root2);
    }
}

void task_3() {
    float a = getFloat("Введите коэффициент a: ", 0, 0, 1, 1);
    float b = getFloat("Введите коэффициент b: ", 0, 0, 1, 1);
    float c = getFloat("Введите коэффициент c: ", 0, 0, 1, 1);

    solveQuadraticEquation(a, b, c);
}