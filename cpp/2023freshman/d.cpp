#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 计算总和
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    // 初始化动态规划数组
    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
    dp[0][0] = 1;

    // 动态规划求解
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            
            if (j + a[i] <= sum) {
                dp[i + 1][j + a[i]] = max(dp[i + 1][j + a[i]], dp[i][j] + (long long)(j * j * j * j * j * j * j * j * j * j) % MOD);
            }
            
            dp[i + 1][sum - (j + a[i])] = max(dp[i + 1][sum - (j + a[i])], dp[i][j] + (long long)((sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j) * (sum - j)) % MOD);
        }
    }

    // 输出结果
    int half = sum / 2;
    long long ans = dp[n][half];
    cout << ans << endl;

    return 0;
}