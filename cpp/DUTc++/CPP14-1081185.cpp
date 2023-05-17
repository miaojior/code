#include<iostream>
#include<algorithm>

using std::endl; using std::cout; using std::cin;

const int STUDENT=20,EXCELLENT_SCORE_LINE=85,PASSING_SCORE_LINE=60;
int id[20],score[20],option,_id;

void printMenu();
void inputScores();
void outputHighScore();
void outputLowScore();
void countAboveAverage();
void sortScores();

int main(){
    while(true){
        printMenu();
        cin>>option;
        switch(option){
            case 1:
                inputScores();
                break;
            case 2:
                outputHighScore();
                break;
            case 3:
                outputLowScore();
                break;
            case 4:
                countAboveAverage();
                break;
            case 5:
                sortScores();
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

void printMenu(){
    cout<<endl<<endl
        <<"高等数学考试成绩管理菜单"<<endl
        <<"1. 学生成绩录入"<<endl
        <<"2. 将考试成绩大于和等于85分的学号和成绩输出"<<endl
        <<"3. 将考试成绩60分以下的学号和成绩输出"<<endl
        <<"4. 统计大于或等于平均分的人数"<<endl
        <<"5. 将20个学生成绩按由高分到低分排序，输出排列好的成绩及每个成绩对应的学号"<<endl
        <<"6. 退出"<<endl
        <<"请选择菜单项（1-6）：";
}

void inputScores(){
    //按学号存储学生成绩
    for(int i=0;i<STUDENT;i++){
        cout<<"请输入第"<<i+1<<"个学生的学号："<<endl;
        cin>>_id;
        cout<<"请输入第"<<i+1<<"个学生的成绩："<<endl;
        cin>>score[_id-1];
    }
    for(int i=0;i<STUDENT;i++)
        id[i]=i; 
}

void outputHighScore(){
    //没说一定有85分以上的，判断是否有大于85分的成绩
    int flag=false;
    for(int i=0;i<STUDENT;i++)
        if(score[i]>=EXCELLENT_SCORE_LINE){
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
    for(int i=0;i<STUDENT;i++)
        if(score[i]>=EXCELLENT_SCORE_LINE)
            printf("%d\t%d\n",i+1,score[i]);
}

void outputLowScore(){
    cout<<"成绩60分以下的学生有："<<endl;
    cout<<"学号\t成绩"<<endl;
    for(int i=0;i<STUDENT;i++)
        if(score[i]<PASSING_SCORE_LINE)
            printf("%d\t%d\n",i+1,score[i]);
}

void countAboveAverage(){
    int sum=0,cnt=0;
    double avg_score;
    for (int i=0;i<STUDENT;i++)
        sum+=score[i];
    avg_score=(double)sum/STUDENT;
    for (int i=0;i<STUDENT;i++)
        if (score[i]>=avg_score) 
            cnt++;
    cout<<"考试平均分为："<<avg_score<<"，大于等于平均分的人数为："<<cnt<<"人"<<endl;
}

void sortScores(){
    cout<<"成绩从大到小排列："<<endl;
    cout<<"学号\t成绩"<<endl;
    for(int i=0;i<STUDENT-1;i++)
        for (int j=0; j<STUDENT-i-1;j++)
            if (score[id[j]]<score[id[j+1]])
                std::swap(id[j],id[j+1]);
//为防止功能5的排序影响功能2功能3的结果，仅对学号进行排序
    for (int i=0;i<STUDENT;i++) 
        printf("%d\t%d\n",id[i]+1,score[id[i]]);
}