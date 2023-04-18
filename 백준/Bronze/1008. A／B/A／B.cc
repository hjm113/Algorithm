#include <stdio.h>
int main() {
    double num1;
    double num2;
    scanf("%lf", &num1);
    scanf("%lf", &num2);
    double sum = num1 / num2;
    printf("%.9lf", sum);
}
