#include <iostream>
using std::cin;using std::cout;using std::endl;

class CDate{
    public:
        CDate(int _year,int _month,int _day);
        CDate(const CDate &that);
        ~CDate();
        inline void print();
        inline void printNextDay();
    private:
        int year,month,day;
        static const int MONTHOFYEAR=12;
        inline bool isleapyear();
        inline int getDaysofMonth();
        inline void addADay();
};

int main(){
    int year,month,day;
    cout<<"当前年：";
    cin>>year;
    cout<<"当前月：";
    cin>>month;
    cout<<"当前日：";
    cin>>day;
    CDate date(year, month, day);
    cout<<"当前日期：";
    date.print();
    cout<<"当前日期后一天的日期：";
    date.printNextDay();
}

CDate::CDate(int _year,int _month,int _day):year(_year),month(_month),day(_day){}
CDate::CDate(const CDate &that):year(that.year),month(that.year),day(that.day){}
CDate::~CDate(){};

inline void CDate::print(){
    cout<<day<<"/"<<month<<"/"<<year<<endl;
}

inline bool CDate::isleapyear(){
    if( !(year%400) || (!(year%4) && year%100) )
        return true;
    else 
        return false;
}

inline int CDate::getDaysofMonth(){
    if(month==2)
        return isleapyear()?29:28;
    else if( month==4 || month==6 || month==9 || month==11 )
        return 30;
    else 
        return 31;
}

inline void CDate::addADay(){
    day++;
    if(day>getDaysofMonth()){
        day=1;month++;
    }
    if(month>MONTHOFYEAR){
        month=1;year++;
    }
}

inline void CDate::printNextDay(){
    addADay();
    print();
}