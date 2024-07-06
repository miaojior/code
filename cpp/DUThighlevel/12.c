#include <stdio.h>
#include <math.h>

int main() {
    double x, e;
    double term, sin_x;
    int n;
    scanf("%lf %lf", &x, &e);
    term = x;
    sin_x = term;
    n = 1;
    do {
        n++;
        term = -term * x * x / (2 * n - 1) / (2 * n - 2);  
        sin_x += term;  
    } while (fabs(term) >= e);  
    printf("%d %.9lf\n", n, sin_x);
    return 0;
}
