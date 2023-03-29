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

/*如果输入的数字m过大使用欧拉筛可极高的提升效率*/
/*
const int N = 100000010;
int primes[N],m,cnt;
bool st[N];

void get_primes(int n){      //euler sieve
    for (int i=2;i<=n;i++){
        if(!st[i])
            primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j]*i]=true;
            if (i%primes[j]==0)break;
        }
    }
}

int main(){
    std::cout<<"输入任意一个正整数: ";
    std::cin>>m;
    get_primes(m);
    for (int i=0;primes[i]<=m/2;++i){
        if (!st[m-primes[i]]){
            std::cout<<"能写成两个素数之和，两个素数是："<<primes[i]<<"和"<<m-primes[i]<<std::endl;
            return 0;
        }
    }
    std::cout << "不能写成两个素数之和" << std::endl;
    return 0;
}
*/