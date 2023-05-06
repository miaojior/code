#include <iostream>
#include <iomanip>
using std::cin; using std::cout; using std::endl;

double y(int n){
    double y;
    if(n&1)//odd
        for(int i=1;i<=n;i+=2) 
            y+=1.0/(2*i+1);
    else{//even
        double t=1.0;
        for (int i=2;i<=n;i+=2){
            t*=(i-1)*i;
            y+=1.0/t;    
        }
    }
    return y;
}

int main(){
    int n;
    while(true){
        cout<<"请输入任意自然整数：";
        cin>>n;
        if(!n)break;
        cout<<endl<<std::fixed<<std::setprecision(6)<<"计算y的值："<<y(n)<<endl;
    }
    cout << "程序结束" << endl;
    return 0;
}