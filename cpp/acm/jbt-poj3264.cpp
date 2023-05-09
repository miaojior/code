#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 50000;

int n, q;
int a[MAXN+1];

struct Node {
    int max_val, min_val;
};

vector<Node> tree(4*MAXN+1);

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].max_val = tree[v].min_val = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        tree[v].max_val = max(tree[2*v].max_val, tree[2*v+1].max_val);
        tree[v].min_val = min(tree[2*v].min_val, tree[2*v+1].min_val);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        Node neutral = {0, (int)1e9}; // Initialize with neutral values
        return neutral;
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    Node left = query(2*v, tl, tm, l, min(r, tm));
    Node right = query(2*v+1, tm+1, tr, max(l, tm+1), r);
    Node res;
    res.max_val = max(left.max_val, right.max_val);
    res.min_val = min(left.min_val, right.min_val);
    return res;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d",&l,&r);
        Node res = query(1, 1, n, l, r);
        printf("%d\n",res.max_val - res.min_val);
    }
    return 0;
}
