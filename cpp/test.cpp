#include <iostream>

int c[3][]={{1,2},{1,2,3},{1,2,3,4}};

int main(){
    for(int i=0;i<2;i++)
    for(int j=0;j<3;j++)
    std::cout<<c[i][j];
}