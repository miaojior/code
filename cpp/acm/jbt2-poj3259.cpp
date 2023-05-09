#include <iostream>
#include <cstdio>
#define inf 1000000
using namespace std;
const int maxn=502;
const int maxm=5210;
int n,m,w,num,dist[maxn];
 
struct Edge
{
    int u;      //边的起点
    int v;      //边的终点
    int w;
}edge[maxm];
 
bool Bellman_Ford()
{
    int i,j;
    bool flag;
    dist[1]=0;
    for(i=1;i<n;i++)
    {
        flag=false;
        for(j=0;j<num;j++)
        if(dist[edge[j].u]+edge[j].w<dist[edge[j].v])
        {
            dist[edge[j].v]=dist[edge[j].u]+edge[j].w;
            flag=true;
        }
        if(!flag)          //不存在负权环
        return false;
    }
    for(i=0;i<num;i++)
    if(dist[edge[i].u]+edge[i].w<dist[edge[i].v])
    return true;         //经过n-1次的松弛操作后还能更新，说明存在负权环
}
 
int main()
{
    int i,j,f,s,e,t;
    scanf("%d",&f);
    while(f--)
    {
        scanf("%d%d%d",&n,&m,&w);
        num=0;
        for(i=0;i<m;i++)     //普通路径，双向边
        {
            scanf("%d%d%d",&s,&e,&t);
            edge[num].u=s;
            edge[num].v=e;
            edge[num++].w=t;
            edge[num].u=e;
            edge[num].v=s;
            edge[num++].w=t;
        }
        for(i=0;i<w;i++)
        {
            scanf("%d%d%d",&s,&e,&t);
            edge[num].u=s;
            edge[num].v=e;
            edge[num++].w=-t;
        }
        for(i=1;i<=n;i++)
        dist[i]=inf;
        if(Bellman_Ford())
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}