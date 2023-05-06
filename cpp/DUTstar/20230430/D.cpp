#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for(int s = 2; s <= 2 * a[n-1]; ++s)
    {
        int l = 0, r = n - 1, cnt = 0; 
        while(l < r)
        {
            if(a[l] + a[r] == s) {++cnt; ++l; --r;}
            else if(a[l] + a[r] < s) ++l;
            else --r; 
        }
        ans = max(ans, cnt);
    }
    cout << (ans<<1) << endl;
    return 0;
}