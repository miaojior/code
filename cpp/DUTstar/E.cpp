#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n;
        int a[10]={0};
        for(int i=1;i<=min(n,1000);i++){
            scanf("%d",&m);
            a[m%10]++;
        }
        bool flag=false;
        for(int i=0;i<10;i++){
            a[i]--;
            for(int j=0;j<10;j++){
                a[j]--;
                for(int k=0;k<10;k++){
                    a[k]--;
                    if(a[i]>=0&&a[j]>=0&&a[k]>=0&&(i+j+k)%10==3){
                    cout<<"Zhen"<<endl;
                    flag=true;
                    }
                    if(flag)
                        break;
                    a[k]++;
                }
                a[j]++;
                if(flag)
                    break;
            }
            if(flag)
                break;
            a[i]++;
        }
        if(!flag)
        cout<<"Jia"<<endl;
    }
    return 0;
}
