#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=2e5+5;
const int MAXLOG=25;

int a[MAXN],n,m,l,r;
int max_st[MAXN][MAXLOG],min_st[MAXN][MAXLOG],log2n[MAXN];

void init(){
    for(int i=1;i<=n;i++)
        max_st[i][0]=min_st[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++){
            max_st[i][j]=max(max_st[i][j-1],max_st[i+(1<<(j-1))][j-1]);
            min_st[i][j]=min(min_st[i][j-1],min_st[i+(1<<(j-1))][j-1]);
        }
    for(int i=2;i<=n;i++)
        log2n[i]=log2n[i>>1]+1;
}

int query_max(int l,int r){
    int len=log2n[r-l+1];
    return max(max_st[l][len],max_st[r-(1<<len)+1][len]);
}
int query_min(int l,int r){
    int len=log2n[r-l+1];
    return min(min_st[l][len],min_st[r-(1<<len)+1][len]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    init();
    while(m--){
        scanf("%d%d",&l,&r);
        printf("%d\n",query_max(l,r)-query_min(l,r));
    }
    return 0;
}