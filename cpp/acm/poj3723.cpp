#include <algorithm>
#include <cstdio>
#define N 100005

struct ITEM {
    int a,b,w;
    bool operator <(const ITEM x)const{
        return w>x.w;
    }
}rela[N];

int fa[N];

int find_root(int p){
    if (fa[p]!=p) 
        fa[p]=find_root(fa[p]);
    return fa[p];
}


int main() {
    int T;
    scanf("%d",&T);
    while (T--){
        int n,m,q,i;
        scanf("%d%d%d",&n,&m,&q);
        for (i=0;i<q;i++)
            scanf("%d%d%d",&rela[i].a,&rela[i].b,&rela[i].w);
        std::sort(rela,rela+q);
        long long ans=0;
        for(int i=0;i<=n+m+1;i++)
            fa[i]=i;
        for(i=0;i<q;i++)
            if(find_root(rela[i].a)!=find_root(rela[i].b+n)){
                fa[find_root(rela[i].b+n)]=find_root(rela[i].a);
                ans-=rela[i].w;
            }
        printf("%lld\n",ans+(n+m)*10000);
    }
    return 0;
}