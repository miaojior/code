#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int n, a[N], len;
int l = 1, r, dir = 1;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    r = n, len = n - 2; // 初始化记录区间的左右端点和长度
    while (len > 0) {
        if (dir == 1) { // 从 A 取出元素插入到 B 中
            if (a[l] < a[r]) { // 判断方向是否需要反转
                dir = -1;
                int tmp = l;
                l = r, r = tmp;
            }
            len--;
            l++;
        } else { // 从 B 取出元素放入到 A 中
            if (a[l] > a[r]) { // 判断方向是否需要反转
                dir = 1;
                int tmp = l;
                l = r, r = tmp;
            }
            len--;
            a[++n] = a[l++];
        }
    }
    for (int i = 2; i < n; i++) { // 判断是否满足非严格单调递增
        if (a[i] > a[i - 1]) continue;
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}