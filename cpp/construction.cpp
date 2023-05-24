#include <iostream>

class A{
    public:
        A(int a=1,int b=2) :a(a),b(b){std::cout<<"constructor "<<a<<std::endl;}
        A(A &that):a(that.a+10),b(that.b){std::cout<<"copy constructor "<<a<<std::endl;}
        ~A(){std::cout<<"destructor "<<a<<std::endl;}
    A f(A a){
    std::cout<<"before return"<<std::endl;
    return a;
    }
    private:
    int a,b; 
};



int main(){
    A object1(3,3),object2(4,4);
    std::cout<<"before f called"<<std::endl;
    object2=object1.f(object1);
    std::cout<<"after f called"<<std::endl;
    return 0;
}