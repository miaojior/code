#include <cstdio>

int main() {
    int m;
    printf("输入任意一个正整数：");
    scanf("%d",&m);
    bool flag=false;
    for(int i=2;i<=m/2;++i) {
        bool isPrime1=true,isPrime2=true;
        for (int j=2;j*j<=i;++j)
            if (i%j==0){
                isPrime1=false;
                break;
            }
        for(int j = 2; j * j <= m - i; ++j)
            if((m-i)%j==0){
                isPrime2=false;
                break;
            }
        if (isPrime1&&isPrime2){
            printf("能写成两个素数之和，两个素数是: %d和%d\n",i,m-i);
            return 0;
        }
    }
    printf("不能写成两个素数之和\n");
    return 0;
}


