#include <cstdio>

const int N=8;
const int dx[8]={-1, 1, -2, 2, -2, 2, -1, 1}; 
const int dy[8]={-2, -2, -1, -1, 1, 1, 2, 2};
bool visited[N][N];
struct step{
    char x,y;
}path[N*N];
bool success;
int T,p,q;

void DFS(int x,int y,int num)
{
    path[num].y=y+'A'-1;
    path[num].x=x+'0';
    if(num==p*q) 
    {
        success=true;
        return;
    }
    for (int i=0;i<8;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (0<nx&&nx<=p&&0<ny&&ny<=q&&!visited[nx][ny]&&!success)
        {
            visited[nx][ny]=true;
            DFS(nx,ny,num+1);
            visited[nx][ny]=false;
        }
    }
}

int main()
{
    scanf("%d", &T);
    for (int t=1;t<=T;t++)
    {
        success = false;
        scanf("%d%d",&p,&q);
        visited[1][1]=true;
        DFS(1,1,1);              
        printf("Scenario #%d:\n",t);
        if(success)
        {
            for(int i=1;i<=p*q;i++)
                printf("%c%c",path[i].y,path[i].x);
            printf("\n");
        }
        else
            printf("impossible\n");
        if (t!=T)
            printf("\n");
    }
    return 0;
}