#include <bits/stdc++.h>
using namespace std;

int num[1000010],a,tot[1000010];
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        scanf("%d",&a);
        num[a]++;
    }
    for (int i = 1; i < 1000010; i++){
        tot[i]=tot[i-1]+num[a];
    }



    int last = 0;
    for (int i = 0; i < m; i++) {
        int b;
        scanf("%d",&b);
        int b_ = (b ^ last) % n;
        printf("%d\n",tot[b_]);
        last += tot[b_];
    }
    
    return 0;
}