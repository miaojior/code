#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main ()
{
    char stuname[5][20],inname[20];
    char subject[][20]= {"高等数学：","英语：","物理："};
    int c[5][3],sum[5],i,j,flag[5],n=0;
    for(i=0; i<5; i++)
    {
        cout<<"第"<<i+1<<"个学生成绩输入:\n";
        cout<<"姓名：";
        cin>>stuname[i];
        for(j=0; j<3; j++)
        {
            cout << subject[j];
            cin >> c[i][j];
            sum[i]+=c[i][j];
        }
    }
    cout << "成绩输入结束!\n\n\n\n输入查询学生姓名:" ;
    cin >> inname;
    for(i=0; i<5; i++)
    {
        if(!strcmp(stuname[i],inname))
        {
            flag[i]=1;
            n++;
        }
       // cout << "成绩综合"<<sum[i] << endl;

    }
    if(n==0)
    {
        cout<<"没有查到该学生\n";
    }
    else
    {
        for(i=0; i<5; i++)
        {   if (!strcmp(stuname[i],inname)){
                //cout<<"flag: "<<flag[i]<<endl;
            cout<<sum[i]<<endl;
            cout<<stuname[i] << "成绩总分:"<< sum[i];
            if(sum[i]>270)
                cout << "\t\t\t\t优秀";
            }
        }
    }
 return 0;
}