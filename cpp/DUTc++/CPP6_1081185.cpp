#include <iostream>
#include <cmath>

int main() {
    int m;
    printf("输入任意一个正整数：");
    scanf("%d",&m);
    for(int i=2;i<=m/2;++i){
        bool isPrime1=true,isPrime2=true;
        for (int j=2;j*j<=i;++j)
            if (i%j==0){
                isPrime1=false;
                break;
            }
        for(int j=2;j*j<=m-i;++j)
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

/*another more efficient solution,  especially for numbers>1e6*/
/*
const int N = 100000010;//the maximum number the program may handle
int primes[N],m,cnt;
bool st[N];

void get_primes(int n){//euler sieve
    for (int i=2;i<=n;i++){
        if(!st[i])
            primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j]*i]=true;
            if (i%primes[j]==0)break;
        }
    }
}

bool isprime(int n){//使用欧拉筛优化试除法，将小于$$sqrt{n}$$的素数先筛出来再试除
    for(int i=0;i<cnt;i++){
    if(!(n%primes[i]))
    return false;
    }
    return true;
}

int main(){
    std::cout<<"输入任意一个正整数: ";
    std::cin>>m;
    if(m<=3){
        std::cout << "不能写成两个素数之和" << std::endl;
        return 0;
    }
    if(m&1){//odd 大于3奇数只能拆成2+一个奇数
        get_primes((int)sqrt(m*1.0));
        if(isprime(m-2))
            std::cout<<"能写成两个素数之和，两个素数是："<<"2"<<"和"<<m-2<<std::endl;
        else
            std::cout << "不能写成两个素数之和" << std::endl;
    }
    else{
    //even 根据哥德巴赫猜想偶数没有不能写成两个素数之和的情况
    //大部分的偶数都能拆成一个较小的素数和一个较大的素数，用优化试除法判断素数可以使平均求得结果的时间期望比直接应用欧拉筛更短
    //但是如果出现特殊情况使试除法效率降低，直接用世界复杂度接近O(n)的欧拉筛比试除法的时间稳定，在特定的时间内更能普适性地解决问题
        get_primes(m);
        for (int i=0;primes[i]<=m/2;++i)
            if (!st[m-primes[i]]){
                std::cout<<"能写成两个素数之和，两个素数是："<<primes[i]<<"和"<<m-primes[i]<<std::endl;
                break;
        }
    }
    return 0;
}
*/