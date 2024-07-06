#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i=2,flag=0;
    for(;i<=n;)
    {
        if(n%i==0)
        {
            if(flag == 0)
                printf("%d ",i);
            n/=i;
            flag++;
        }
        else
        {
           i++;
           flag=0;
        }
   }
   return 0;
   }
      

