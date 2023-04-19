#include <iostream>
#include <cstring>
using std::cin,std::cout,std::endl;

const int subject=3,charlength=20,student=5;
char names[student][charlength],queryName[20];
int scores[5],score;

int main(){
    for (int i=0;i<student;i++){
        cout<<"第"<<i+1<<"个学生成绩输入："<<endl<<"姓名：";
        cin>>names[i];
        for(int j=0;j<subject;j++){
            cout<<(j==0?"高等数学":(j==1?"英语":"物理"))<<"：";
            cin>>score;
            scores[i]+=score;
        }
    }
    
    cout<<"成绩输入结束！"<<endl<<"输入查询学生姓名：";
    cin>>queryName;
    
    for (int i=0;i<student;i++)
        if (!strcmp(names[i],queryName)){
            cout<<queryName<<"成绩总分："<<scores[i];
            if(scores[i]>270)
                cout<<"\t优秀";
            cout<<endl;
            return 0;
    } 
    cout<<"没有查到该学生"<<endl;
    return 0;
}