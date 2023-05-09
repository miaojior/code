#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,ans; 
char w[10010],t[1000010];
int fail[1000010];
int main()
{
	scanf("%d",&n); 
	while (n--){
		memset(fail,0,sizeof(fail));
		ans=0;
		scanf("%s%s",w+1,t+1);
		int lenw=strlen(w+1);
		int lent=strlen(t+1);
		
		fail[1]=0;
		fail[0]=-1;
		for (int i=2;i<=lent;i++){
			int p=fail[i-1];
			while ((p!=-1) && (t[p+1]!=t[i]))
				p=fail[p];
			fail[i]=p+1;
		}
		
		int ind=0;
		for (int i=1;i<=lent;i++){
			while (ind!=-1 && t[i]!=w[ind+1])
				ind=fail[ind];
			ind++;
			if (ind==lenw) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
//24128797	playerone	3461	Accepted	5224K	157MS	G++	622B	2023-05-08 19:07:10