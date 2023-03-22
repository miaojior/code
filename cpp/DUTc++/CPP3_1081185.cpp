#include <stdio.h>
#include <math.h>

int main()
{
    const double x1=4, y1=6, r=2; // 圆心坐标和半径
    double x2,y2; // 点M的坐标
    printf("输入任意一个点位置: ");
    scanf("%lf,%lf", &x2, &y2);
    double d=sqrt(pow(x1-x2,2)+pow(y1-y2,2)); // 计算点到圆心的距离
    if(d>r)
        printf("输入点在圆外\n");
    else if(d==r)
        printf("输入点在圆上\n");
    else
        printf("输入点在圆内\n");
    return 0;
}