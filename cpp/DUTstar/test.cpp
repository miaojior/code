#include <iostream>

using namespace std;

int main(){
    for(int i=0;i<=9;i++)
    for(int j=0;j<=9;j++)
    for(int k=0;k<=9;k++)
    if((i+j+k)%10==3)
    cout<<i<<"+"<<j<<"+"<<k<<"="<<i+j+k<<endl;
    return 0;
}