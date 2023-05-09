#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 10010;
const int maxm = 50010;
struct Edge {
    int from;
    int to;
    int dis;
    bool friend operator < (Edge a, Edge b) {
        return a.dis > b.dis;
    }
};
Edge edge[maxm];
int father[maxn << 1];
int FindFather(int x) {
    int a = x;
    while (x != father[x]) x = father[x];
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void UnionFather(int a, int b) {
    int fa = FindFather(a);
    int fb = FindFather(b);
    if (fa != fb) father[fa] = fb;
}
int main() {
    ios::sync_with_stdio(false);
    int t, n, m, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &r);
        for (int i = 0; i < n + m; i++) father[i] = i;
        for (int i = 0; i < r; i++) {
            scanf("%d %d %d", &edge[i].from, &edge[i].to, &edge[i].dis);
            edge[i].to += n;
        }
        sort(edge, edge + r);
        int ans = 0;
        for (int i = 0; i < r; i++) {
            if (FindFather(edge[i].from) != FindFather(edge[i].to)) {
                UnionFather(edge[i].from, edge[i].to);
                ans += edge[i].dis;
            }
        }
        printf("%d\n", (n + m) * 10000 - ans);
    }
    return 0;
}
