#include <bits/stdc++.h>

using namespace std;

bool a[10000010];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        int n,x;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&x);
            a[x]=true;
        }
        for(int i=0;;i++)
        if(!a[i]){
        printf("%d\n",i);
        break;
        }
    }
    return 0;
}