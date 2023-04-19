#include <iostream>
#include <cstring>
using std::cin,std::cout,std::endl;

int main(){
    char names[5][20],queryName[20];
    int math[5],english[5],physics[5];
    for (int i=0;i<5;i++){
        cout<<"第"<<i+1<<"个学生成绩输入："<<endl<<"姓名：";
        cin>>names[i];
        cout<<"高等数学：";
        cin>>math[i];
        cout<<"英语：";
        cin>>english[i];
        cout<<"物理：";
        cin>>physics[i];
    }
    
    cout<<"成绩输入结束！"<<endl<<"输入查询学生姓名：";
    cin>>queryName;
    
    int flag=-1;
    for (int i = 0; i < 5; i++)
        if (!strcmp(names[i],queryName)){
            flag = i;
            break;
        }
    if (flag != -1){
        int totalScore=math[flag]+english[flag]+physics[flag];
        cout<<queryName<<"成绩总分："<<totalScore;
        if(totalScore>270)
            cout << "    优秀";
        cout<<endl;
    } 
    else
        cout << "没有查到该学生" << endl;
    return 0;
}
