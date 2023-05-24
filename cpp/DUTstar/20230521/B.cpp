#include <bits/stdc++.h>
using namespace std;
int T;
long long num;

int main() {
    //ofstream fin("num.out");
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&num);
        int a=(long long)ceil(sqrt(((double)num/4)));
        int b=(long long)(ceil((1+sqrt(1+4*((double)(num-1.0)/4)))/2));
        //cout<<a<<" "<<b<<endl;
        if(num==1)
        printf("0\n");
        else
        printf("%d\n",min(2*a-1,2*(b-1)));
    }
    return 0;
}