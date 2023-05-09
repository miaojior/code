#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF=1e9;
const int MAXN=2510;
const int MAXM=5500;

struct Edge {
    int from,to,weight;
    Edge(int u,int v,int w):from(u),to(v),weight(w){}
};

vector<Edge> graph[MAXN];
int dist[MAXN];
bool visited[MAXN];
int cnt[MAXN];

int n,m,w;
bool dijkstra(int start){
    memset(dist,INF,sizeof(dist));
    memset(cnt,0,sizeof(cnt));
    memset(visited,false,sizeof(visited));
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push(make_pair(0,start));
    dist[start]=0;
    visited[start]=true;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        visited[u]=false;
        for (int i=0;i<graph[u].size();i++){
            int v=graph[u][i].to;
            int w=graph[u][i].weight;
            if (dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                if(!visited[v]){
                    q.push(make_pair(dist[v],v));
                    visited[v]=true;
                    cnt[v]++;
                    if(cnt[v]>=n)
                        return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>w;
        for(int i=1;i<=n;i++)
            graph[i].clear();
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back(Edge(u,v,w));
            graph[v].push_back(Edge(v,u,w));
        }
        for(int i=0;i<w;i++){
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back(Edge(u,v,-w));
        }
        bool flag=false;
        for (int i=1;i<=n;i++)
            if(dijkstra(i)){
                flag=true;
                break;
            }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
