#include <bits/stdc++.h>

using namespace std;

const int N=43820;
struct node{
    int  level,airplane,airport_to,airport_from,warning,phase;
}a[50000];

int airport_warning[117][50];
int airport_warning_level2[117][50],airport_warning_level3[117][50];

int main(){
    freopen("./in.csv","r",stdin);
    freopen("./output.txt","w",stdout);
    for(int i=1;i<=N;i++)
    cin>>a[i].level>>a[i].airplane>>a[i].airport_to>>a[i].airport_from>>a[i].warning>>a[i].phase;


    for(int i=1;i<N;i++){
        if(a[i].phase==6||a[i].phase==2){
        airport_warning[a[i].airport_from][a[i].warning]++;
        if(a[i].level==2)
        airport_warning_level2[a[i].airport_to][a[i].warning]++;
        else
        airport_warning_level3[a[i].airport_to][a[i].warning]++;
        }
    }
    for(int i=1;i<=116;i++){
        for(int j=1;j<=49;j++)
        cout<<airport_warning_level3[i][j]<<" ";
        cout<<endl;
    }

  // for(int i=1;i<=N;i++)
  // cout<<a[i].level<<" "<<a[i].airplane<<" "<<a[i].airport_to<<" "<<a[i].airport_from<<" "<<a[i].warning<<" "<<a[i].phase<<endl;

}