#include <iostream>
#include <cstring>
using std::cout,std::endl,std::cin;

char str1[100010];
int n;

int main() {
    cout<<"输入字符串：";
    cin>>str1;
    cout<<"输入数字n：";
    cin>>n;
    if(n>=strlen(str1))
        cout<<"输入数字大于字符串长度，不能逆序操作"<<endl;
    else{
        cout<<"反转后的字符串为：";
        while(n--)
            cout<<str1[n];
        cout<<endl;
    }
    return 0;
}