#include <iostream>

using std::cin; using std::cout; using std::endl;

const int EMPLOYEE=10,A_LEVEL_OF_SALARY=220,YEARS_OF_WORK_LIMIT=10;
struct Employee{
    std::string name;
    int years_of_work,salary;
}employees[EMPLOYEE];
int total_salary;

void printMenu();
void inputEmployeeInformation();
void increaseSalaryForAll();
void increaseSalaryForSeniorEmployees();
void queryTotalSalary();
void sortSalary();

int main(){
    int choice;
    while(true){
        printMenu();
        cin>>choice;
        switch(choice){
            case 1:
                inputEmployeeInformation();
                break;
            case 2:
                increaseSalaryForAll();
                break;
            case 3:
                increaseSalaryForSeniorEmployees();
                break;
            case 4:
                queryTotalSalary();
                break;
            case 5:
                sortSalary();
                break;
            case 6:
                cout<<"程序结束！"<<endl;
                return 0;
            default:
                cout<<"无效的菜单选项，请重新选择。"<<endl;
                break;
        }
    }
}

void printMenu(){
    cout<<endl<<endl
        <<"职工工资管理菜单"<<endl
        <<"1. 录入职工工资信息"<<endl
        <<"2. 每个职工的工资普涨一级工资"<<endl
        <<"3. 10年以上员工工资增加一级工资"<<endl
        <<"4. 查询并输出公司工资总额"<<endl
        <<"5. 职工工资信息排序输出（由高到低）"<<endl
        <<"6. 退出"<<endl
        <<"请选择菜单项（1-6）：";
}     

void inputEmployeeInformation(){
     for(int i=0;i<10;i++){
        cout<<"输入第"<<(i+1)<<"个职工姓名：";
        cin>>employees[i].name;
        cout<<"输入第"<<(i+1)<<"个职工工龄：";
        cin>>employees[i].years_of_work;
        cout<<"输入第"<<(i+1)<<"个职工工资：";
        cin>>employees[i].salary;
        total_salary+=employees[i].salary;
    }
}

void increaseSalaryForAll(){
    for(int i=0;i<EMPLOYEE;i++)
        employees[i].salary+=A_LEVEL_OF_SALARY;
    total_salary+=EMPLOYEE*A_LEVEL_OF_SALARY;
    cout<<"已经普涨一级工资，公司工资总额为："<<total_salary<<"元"<<endl;
}

void increaseSalaryForSeniorEmployees(){
    int cnt=0;
    for(int i=0;i<EMPLOYEE;i++)
        if(employees[i].years_of_work>=YEARS_OF_WORK_LIMIT){
            employees[i].salary+=A_LEVEL_OF_SALARY;
            cnt++;
        }
    total_salary+=cnt*A_LEVEL_OF_SALARY;
    cout<<"已经为10年以上员工再增加一级工资，增加人数为："<<cnt<<"人"<<endl;
}

void queryTotalSalary(){
    cout<<"目前公司工资总额为："<<total_salary<<"元"<<endl;
}

void sortSalary(){
    for(int i=0;i<EMPLOYEE-1;i++)
        for(int j=0;j<EMPLOYEE-1;j++)
            if(employees[j].salary<employees[j+1].salary){
                Employee tmp=employees[j+1];
                employees[j+1]=employees[j];
                employees[j]=tmp;
            }
    cout<<"公司职工工资信息如下："<<endl
        <<"姓名\t工龄\t工资"<<endl;
    for(int i=0;i<EMPLOYEE;i++)
        cout<<employees[i].name<<"\t"<<employees[i].years_of_work<<"\t"<<employees[i].salary<<endl;
}