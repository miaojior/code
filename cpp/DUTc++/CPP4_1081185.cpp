#include <stdio.h>

int main(){
    int year, month;
    printf("输入年和月: ");
    scanf("%d,%d",&year,&month);
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("%d年%d月有31天\n", year, month);
            break;
        case 4: case 6: case 9: case 11:
            printf("%d年%d月有30天\n", year, month);
            break;
        case 2:
            if( ( !(year%4) && year%100 )||!(year%400)) 
                printf("%d年%d月有29天\n",year,month);
            else
                printf("%d年%d月有28天\n",year,month);
            break;
    }
    return 0;
}