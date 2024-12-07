#include <stdio.h>
#include "calculate_edit.h"

int main(void) {
    float Numeral;
    char Operation[4];
    float result;

    printf("Введите число: ");
    (void)scanf("%f", &Numeral);  // Игнорируем результат
    printf("Введите операцию (+, -, *, /, pow, sqrt, sin, cos, tan): ");
    (void)scanf("%s", Operation);  // Игнорируем результат

    result = Calculate(Numeral, Operation);
    printf("%6.2f\n", result);
    return 0;
}