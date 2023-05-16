#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseString(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
    return s;
}

string longestPalindromicSubstring(string s) {
    string T = "#";
    for (char c : s) {
        T += c;
        T += "#";
    }

    int n = T.size();
    vector<int> P(n);

    int C = 0, R = 0;
    for (int i = 0; i < n; i++) {
        int mirror = 2 * C - i;

        if (R > i) {
            P[i] = min(R - i, P[mirror]);
        } else {
            P[i] = 0;
        }

        while (i - P[i] - 1 >= 0 && i + P[i] + 1 < n && T[i - P[i] - 1] == T[i + P[i] + 1]) {
            P[i]++;
        }

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int maxLen = 0, centerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s ;
    int n;
    cin>>n>>s;
    string sReversed = reverseString(s);
    string longestPalindrome = longestPalindromicSubstring(sReversed);
    cout << longestPalindrome << endl; // 输出 dcba
    int len= longestPalindrome.length();
    //cout<<len<<endl;
    for(int i=n-len;i>0;i--)
    s=s+s[i-1];
    cout<<s<<endl;
    return 0;
}
