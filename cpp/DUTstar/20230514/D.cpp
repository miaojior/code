#include <iostream>
#include <vector>
#include <random>
#include <numeric>
using namespace std;

using ll = long long;

// 生成随机数
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand_int(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// 求 x 的二进制表示中最高位的幂次
int get_highest_bit(ll x) {
    int res = 0;
    while (x) {
        x >>= 1;
        ++res;
    }
    return res - 1;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
        int highest_bit = get_highest_bit(i);
        ll x = a[i-1] / (n-1);
        ll b;
        do {
            b = rand_int(1, 1e9);
        } while (get_highest_bit(i) < highest_bit);
        a[i] = (n-1) * (x * (n-1) + b) ^ a[i-1];
    }

    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
