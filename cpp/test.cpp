#include <bits/stdc++.h>

using namespace std;

class A{
public:
    A(){print();};
    void print(){
        cout<<"A"<<endl;
    }
};

class B:public A{
public:
    B(){print();};
    void print(){
        cout<<"B"<<endl;
    }
};


int main(){
    A a;
    B b;
    return 0;
}