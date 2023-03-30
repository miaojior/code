#include<stdio.h>


int main()
{
    int i=3,j=5;
    float x=2.5;
    double y=5.0;
    y+=i-=j*=++x;
    printf("%lf",y);
}