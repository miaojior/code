#include <iostream>

int f(int a){
    return a;
}

int ff(int a){
    return a;
}

int main(){
    char *p="hello world";
    int a=0;
    printf("%p\n",p);
    std::cout<<ff(a)<<std::endl<<&a<<std::endl;
    std::cout<<&main<<" "<<&ff<<std::endl;
    return 0;
}