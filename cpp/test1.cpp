#include <bits/stdc++.h>

using std::cout,std::cin,std::endl;

int main()
{
    double a_1,a_2,D_1,D_2,_c,d_1;
    cout << "请输入a_1的值：" ;
    cin >> a_1;
    cout << "请输入a_2的值：";
    cin >> a_2;
    cout << "请输入D_1的值：";
    cin >> D_1;
    cout << "请输入D_2的值：";
    cin >> D_2;
    cout << "请输入_c的值：";
    cin >> _c;
    cout << "请输入d_1的值：";
    cin >> d_1;
    cout<<"_K= "<<((a_1*D_2-a_2*D_1)*_c)/(a_1*a_2*(d_1-D_2))<<endl;
}