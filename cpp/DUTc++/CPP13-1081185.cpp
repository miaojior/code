#include <iostream>
#include <cstring>
using std::cin; using std::cout; using std::endl;

const int MAXN=10010;
char s[MAXN];
int i,n;

void del(char s[],int i,int n){
    int len=strlen(s);
    //memmove(s+i-1, s+i+n-1, len-i-n+2);
    for (int j=i+n-1;j<=len;j++)
        s[j-n]=s[j];
    return ;
}

int main(){
    cout<<"请输入一条任意字符串：";
    cin.getline(s,MAXN);
    cout<<"请输入要删除字符的开始位置：";
    cin>>i;
    cout<<"请输入要删除字符的个数：";
    cin>>n;
    del(s,i,n);
    cout<<"删除字符后的字符串：" << s << endl;
    return 0;
}