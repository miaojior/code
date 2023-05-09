#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <string.h>
using namespace std;
 
void solve() {
    string s, p;
    cin >> p >> s;
    int lenp = p.size();
    int lens = s.size();
    vector<int> next(lenp + 1);
    next[0] = -1;
    int j = 0, k = -1;
    while (j < lenp) {
        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            if (p[j] == p[k]) {
                next[j] = next[k];
            }
            else {
                next[j] = k;
            }
        }
        else {
            k = next[k];
        }
    }
    int ans = 0;
    int i = 0;
    j = 0;
    while (i < lenp && j < lens) {
        if (i == -1 || p[i] == s[j]) {
            i++;
            j++;
        }
        else {
            i = next[i];
        }
        if (i == lenp) {
            ans++;
            i = next[i];
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
//24128823	jbt	3461	Accepted	1460K	219MS	G++	1118B	2023-05-08 19:22:11