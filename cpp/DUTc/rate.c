#include <stdio.h>
#include <math.h>

int main()
{
    int money,year; 
    double rate,sum;
    scanf("%d%d%lf", &money,&year,&rate); 
    sum = money * pow(1 + rate, year);
    printf("sum=%7.2f\n", sum);
    return 0;
}