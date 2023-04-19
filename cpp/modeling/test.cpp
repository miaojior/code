#include <bits/stdc++.h>

using namespace std;

struct node{
    int warninglevel,airplane;
    int airport_from,airport_to;
    int year,month,day;
    int phase,yearmonth;
    std::string warning,phase_cn;
}a[101000];

int main()
{
    freopen("./in.txt","r",stdin);
    int i=1;int year,month,day;
    scanf("%d %d号机 机场%d %d %d %d 机场%d",&a[i].warninglevel,&a[i].airplane,&a[i].airport_to,&a[i].year,&a[i].month,&a[i].day,&a[i].airport_from);
     cout<<a[i].warninglevel<<" "<<a[i].airplane<<" "<<a[i].airport_to<<" "<<a[i].year<<" "<<a[i].month<<" "<<a[i].day<<" "<<a[i].airport_from<<" ";
    return 0;
}