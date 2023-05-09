#include <cstdio>
#include <cstring>

const int MAXLEN = 1e6+10;
char W[MAXLEN],T[MAXLEN];
int next[MAXLEN];

int KMP(char *W,char *T){
    int wlen=strlen(W),tlen=strlen(T);
    memset(next,0,sizeof(next));
    int j=0;
    for (int i=1;i<wlen;i++){
        while (j>0&&W[i]!=W[j]) 
            j=next[j-1];
        if (W[i]==W[j])
            j++;
        next[i]=j;
    }
    int count=0;
    j=0;
    for (int i=0;i<tlen;i++){
        while(j>0&&T[i]!=W[j])
            j=next[j-1];
        if (T[i]==W[j])
            j++;
        if (j==wlen){
            count++;
            j=next[j-1];
        }
    }
    return count;
}

int main(){
    int testCases;
    scanf("%d",&testCases);
    while (testCases--){
        scanf("%s%s",W,T);
        printf("%d\n",KMP(W,T));
    }
    return 0;
}