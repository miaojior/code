#include <iostream>
const int MAXN = 200001;

int n, m;
int a[MAXN], maxrmq[MAXN][51], minrmq[MAXN][51];

int max(int l,int r){
    int k=0;
    while(l+(1<<(k+1))<=r+1)
        k++;
    return std::max(maxrmq[l][k],maxrmq[r-(1<<k)+1][k]);
}

int min(int l, int r){
    int k=0;
    while(l+(1<<(k+1))<=r+1)
        k++;
    return std::min(minrmq[l][k],minrmq[r-(1<<k)+1][k]);
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<=n;i++)
        maxrmq[i][0]=minrmq[i][0]=a[i];
    for(int j=1;j<=25;j++){
        for(int i=1;i+(1<<j)<= n + 1; i++) {
            maxrmq[i][j]=std::max(maxrmq[i][j-1],maxrmq[i+(1<<(j-1))][j-1]);
            minrmq[i][j]=std::min(minrmq[i][j-1],minrmq[i+(1<<(j-1))][j-1]);
        }    
    }

    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",max(x,y)-min(x,y));
    }
    return 0;
}