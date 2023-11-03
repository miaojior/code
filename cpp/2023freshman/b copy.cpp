#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    int last = 0;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        
        int b_ = (b ^ last) % n;
        
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] <= b_) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        
        last += left;
        cout << left << endl;
    }
    
    return 0;
}