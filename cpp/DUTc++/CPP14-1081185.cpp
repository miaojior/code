#include<iostream>
#include<algorithm>

using std::endl; using std::cout; using std::cin;

int id[20],score[20],option,_id;
const int n=20;

void input_scores(){
    //按学号存储学生成绩
    cout<<"请输入学生学号和成绩，共"<<n<<"人（一行两个数，用空格分割）："<<endl;
    for (int i=0;i<n;i++)
        cin>>_id>>score[_id-1];
    for (int i=0;i<n;i++)
        id[i]=i;
}

void output_high_score(){
    //判断是否有大于85分的成绩
    int flag=false;
    for(int i=0;i<20;i++)
        if(score[i]>=85){
            flag=true;
            break;
        }
    if(!flag){
        cout<<"成绩大于等于85分的学生不存在"<<endl;
        return ;
    }
    //满足条件输出成绩
    cout<<"成绩大于等于85分的学生有："<<endl;
    cout<<"学号\t成绩"<<endl;
    for(int i=0;i<n;i++)
        if(score[i]>=85)
            printf("%d\t%d\n",i+1,score[i]);
}

void output_low_score(){
    cout<<"成绩60分以下的学生有："<<endl;
    cout<<"学号\t成绩"<<endl;
    for(int i=0;i<n;i++)
        if(score[i]<60)
            printf("%d\t%d\n",i+1,score[i]);
}

void count_above_average(){
    int sum=0,cnt=0;
    double avg_score;
    for (int i=0;i<n;i++)
        sum+=score[i];
    avg_score=(double)sum/n;
    for (int i=0;i<n;i++)
        if (score[i]>=avg_score) 
            cnt++;
    cout<<"考试平均分为："<<avg_score<<"，大于等于平均分的人数为："<<cnt<<"人"<<endl;
}

void sort_scores(){
    cout<<"成绩从大到小排列："<<endl;
    cout<<"学号\t成绩"<<endl;
    for(int i=0;i<n-1;i++)
        for (int j=0; j<n-i-1;j++)
            if (score[id[j]]<score[id[j+1]])
                std::swap(id[j],id[j+1]);
//为防止功能5的排序影响功能2功能3的结果，仅对学号进行排序
    for (int i=0;i<n;i++) 
        printf("%d\t%d\n",id[i]+1,score[id[i]]);
}

int main(){
    while(true){
        cout<<endl<<"高等数学考试成绩管理菜单"<<endl;
        cout<<"1. 学生成绩录入"<<endl;
        cout<<"2. 将考试成绩大于和等于85分的学号和成绩输出"<<endl;
        cout<<"3. 将考试成绩60分以下的学号和成绩输出"<<endl;
        cout<<"4. 统计大于或等于平均分的人数"<<endl;
        cout<<"5. 将20个学生成绩按由高分到低分排序，输出排列好的成绩及每个成绩对应的学号"<<endl;
        cout<<"6. 退出"<<endl;
        cout<<"请选择菜单项（1-6）：";
        cin>>option;
        switch(option){
            case 1:
                input_scores();
                break;
            case 2:
                output_high_score();
                break;
            case 3:
                output_low_score();
                break;
            case 4:
                count_above_average();
                break;
            case 5:
                sort_scores();
                break;
            case 6:
                cout<<"程序结束！"<<endl;
                return 0;
            default:
                cout<<"输入有误，请重新选择"<<endl;
                break;
        }
    }
}