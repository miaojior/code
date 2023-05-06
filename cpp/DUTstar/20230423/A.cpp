#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010, M = 20010;

int h[N], e[M], w[M], ne[M], idx;
int n, m, s, t;
int dist[N], pre[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;   // 小根堆
    heap.push({ 0, s });

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                pre[j] = ver;   // 记录前驱节点
                heap.push({ dist[j], j });
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> t;

    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dijkstra();

    cout << dist[t] << endl;

    int i = t;
    int path[N], cnt = 0;
    while (i != s)
    {
        path[cnt ++ ] = i;
        i = pre[i];
    }
    path[cnt ++ ] = s;

    for (int i = cnt - 1; i >= 0; i -- ) cout << path[i] << ' ';

    return 0;
}
