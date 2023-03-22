#include <stdio.h>
#include <math.h>

int main()
{
    double a=1, b=1, c=-2;
    double delta = b * b - 4 * a * c;
    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);
    printf("x1=%.4f\nx2=%.4f\n", x1, x2);
    return 0;
}