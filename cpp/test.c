#include <stdio.h>

int main(){
    int (*p)[10];
    int a[20]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
    p=&a[0];
    printf("%d",(*p)[11]);
    return 0;
} 