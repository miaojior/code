#include <cstdio>
#include <math.h>

int main()
{
    double a, b, c;
    printf("����һԪ���η���ϵ��: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double delta = b * b - 4 * a * c;
    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);
    printf("���һԪ���η��̵�ʵ��: %.4f,%.4f\n", x1, x2);
    return 0;
}