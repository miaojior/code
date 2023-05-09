#include<iostream>
#include<cstring>
#include<cstdio>
using  namespace std;
 
int p, q, flag;
int visit[30][30];
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
struct node {
    int x;
    int y;
} chess[30];
 
void dfs(int x, int y, int step)
{
    chess[step].x = x;
    chess[step].y = y;
    if(step == p * q) {
        for(int i = 1; i <= step; i++) {
            cout << char(chess[i].y-1+'A') << chess[i].x;
        }
        cout << endl;
        flag = 1;
    }
    if(flag)
        return;
    for(int i = 0; i < 8; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X > 0 && X <= p && Y > 0 && Y <= q && visit[X][Y] == 0) {
            visit[X][Y]  = 1;
            dfs(X, Y, step + 1);
            visit[X][Y]  = 0;
        }
    }
}
 
int main()
{
    int n;
    int Case = 1;
    cin >> n;
    while(n--) {
        memset(visit, 0, sizeof(visit));
        flag = 0;
        cin >> p >> q;
        cout << "Scenario #" << Case++ << ":" << endl;
        visit[1][1] = true;
        dfs(1, 1, 1);
        if(flag == false)
            cout << "impossible" << endl;
        cout << endl;
    }
    return 0;
}
//24128942	jbt	2488	Accepted	376K	16MS	G++	1177B	2023-05-08 20:32:37