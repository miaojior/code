#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAXN = 2510;
const int MAXM = 5500;

struct Edge {
    int from, to, weight;
    Edge(int u, int v, int w): from(u), to(v), weight(w) {}
};

vector<Edge> graph[MAXN]; // 邻接表存储图
int dist[MAXN]; // 存储起点到每个点的最短距离
bool visited[MAXN]; // 标记每个点是否在队列中
int cnt[MAXN]; // 维护每个点入队次数

int n, m, w; // 点数、边数、虫洞数

bool spfa(int start) {
    memset(dist, INF, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = false;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    cnt[v]++;
                    if (cnt[v] >= n) return true; // 入队次数超过 n，说明存在负环，返回 true
                }
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m >> w;

        // 清空邻接表
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }

        // 构建图
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(Edge(u, v, w));
            graph[v].push_back(Edge(v, u, w));
        }
        for (int i = 0; i < w; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(Edge(u, v, -w)); // 虫洞的边权为负数
        }

        // 判断是否存在负环
        bool hasNegativeCycle = false;
        for (int i = 1; i <= n; i++) {
            if (spfa(i)) {
                hasNegativeCycle = true;
                break;
            }
        }

        // 输出结果
        if (hasNegativeCycle) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}