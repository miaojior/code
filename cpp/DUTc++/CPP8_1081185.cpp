#include <iostream>

#define subjectj (j==0?"高等数学":(j==1?"英语":"物理"))
const int Students=10,Subjects=3;
double scores[Students][Subjects],averages,excellent_rates;

int main(){
    //read input
    for(int i=0;i<Students;i++){
        std::cout<<"第"<<i+1<<"个学生成绩输入"<<std::endl;
        for (int j = 0; j < Subjects; j++) {
            std::cout<<"请输入"<<subjectj<<"的成绩：";
            std::cin>>scores[i][j];
        }
    }
    std::cout<<" 输入结束！"<<std::endl;

    //Calculate and output the average grade of each student
    for(int i=0;i<Students;i++){
        double sum=0;
        std::cout<<"第"<<i+1<<"个学生成绩："<<std::endl;
        for(int j=0;j<Subjects;j++){
            std::cout<<subjectj<<": "<<scores[i][j]<<std::endl;
            sum+=scores[i][j];
        }
        averages=sum/Subjects;
        std::cout<<"平均成绩: ";
        printf("%.1lf\n",averages);
    }

    //Calculate and output the excellent rate of each subject
    for (int j=0;j<Subjects;j++){
        int excellent_count=0;
        for (int i=0;i<Students;i++)
            if (scores[i][j] >= 90)
                excellent_count++;
        excellent_rates=(double)excellent_count/Students*100;
        std::cout<<subjectj<<"课优秀率：";
        printf("%.2lf\n",excellent_rates);
    }
    return 0;
}