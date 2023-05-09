#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 50001

struct edge
{
	int u,v,cost;
};
int T,N,M,R;
int x[maxn],y[maxn],d[maxn];
edge es[maxn];
int par[maxn];
int rank[maxn];

bool comp(const edge&e1,const edge&e2)
{
	return e1.cost<e2.cost;
}
void init(int n)
{
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
}
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return ;
	if(rank[x]<rank[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
int kruskal()
{
	std::sort(es,es+R,comp);
	init(N+M);
	int res=0;
	for(int i=0;i<R;i++)
	{
		edge e=es[i];
		if(!same(e.u,e.v))
		{
			unite(e.u,e.v);
			res+=e.cost;
		}
	}
	return res;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&M,&R);
		for(int i=0;i<R;i++)
			scanf("%d%d%d",&x[i],&y[i],&d[i]);
		for(int i=0;i<R;i++)
			es[i]=(edge){x[i],y[i]+N,-d[i]};
		printf("%d\n",10000*(N+M)+kruskal());	
	}
	return 0;
}
