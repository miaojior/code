#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Manacher算法求最长回文子串
string manacher(string s) {
    int n = s.size();
    string t = "#";
    for (int i = 0; i < n; i++) {
        t += s[i];
        t += "#";
    }
    n = t.size();
    vector<int> p(n, 0);
    int id = 0, mx = 0, max_len = 0, max_center = 0;
    for (int i = 0; i < n; i++) {
        if (mx > i) {
            p[i] = min(p[2 * id - i], mx - i);
        } else {
            p[i] = 1;
        }
        while (i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > mx) {
            id = i;
            mx = i + p[i];
        }
        if (p[i] - 1 > max_len && i + p[i] == n) {
            max_len = p[i] - 1;
            max_center = i;
        }
    }
    string ans;
    for (int i = max_center - max_len + 1; i <= max_center + max_len - 1; i += 2) {
        ans += t[i];
    }
    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // 找到所有以字符串结尾的回文子串
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    vector<string> prefix_palindromes;
    for (int i = 0; i < n; i++) {
        if (s.substr(i) == rev_s.substr(0, n - i)) {
            prefix_palindromes.push_back(manacher(s.substr(i)));
        }
    }

    // 找到最长的回文子串
    string max_palindrome;
    int max_len = 0;
    for (const auto& p : prefix_palindromes) {
        if (p.size() > max_len) {
            max_len = p.size();
            max_palindrome = p;
        }
    }

    cout << max_palindrome << endl;

    return 0;
}
