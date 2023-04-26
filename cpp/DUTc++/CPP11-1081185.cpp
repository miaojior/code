#include <iostream>
using std::cout; using std::endl; using std::cin;
const int N = 10;
int a[N];
int *pmax[N], *pmin[N];
int cnt_max = 1, cnt_min = 1;

int main() {
    cout << "请输入任意10个数：";
    for (int i=0;i<N;i++)
        cin >> a[i];
        
    pmax[0]=pmin[0]=&a[0];
    for (int i=1;i<N;i++){
        //since there is 10 random integers,the maximun value of the numbers may apper more than once
        if (*pmax[0]<a[i]){
            //set cnt_max to 1 to clear the storage and store the pointer of current maximun number,when a greater number appears  
            pmax[0]=&a[i];
            cnt_max=1;
        }else if(*pmax[0]==a[i])
        //store the number in array,when maximun number apper more than once
            pmax[cnt_max++]=&a[i];
        if (*pmin[0] > a[i]){//handle the minimun number
            pmin[0]=&a[i];
            cnt_min=1;
        }else if(*pmin[0]==a[i])
            pmin[cnt_min++]=&a[i];
    }

    cout<<"数组首地址:  "<<&a[0]<<"，数组首地址值"<<a[0]<<endl;
    cout<<"最大数地址： "<<pmax[0]<<"，最大数："<<*pmax[0]<<endl;
    cout<<"最小数地址： "<<pmin[0]<<"，最小数："<<*pmin[0]<<endl;
    /*cout<<"最大数地址： ";
    for (int i=0;i<cnt_max;i++)
        cout<<pmax[i]<<"，";
    cout<<"最大数：" <<*pmax[0]<<endl;
    cout<<"最小数地址： ";
    for (int i=0;i<cnt_min;i++)
        cout << pmin[i] << "，";
    cout<<"最小数："<<*pmin[0]<<endl;*/
    return 0;
}