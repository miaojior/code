#include<iostream>

int main(){
    printf("母鸡\t公鸡\t小鸡\n");
    int hen,cock,chick;
    for(hen=0;hen<=33;hen++){
        for(cock=0;cock*2<=100-hen*3;cock++){
            chick=2*(100-hen*3-cock*2); //The price of chicks is calculated by subtracting the prices of hens and cocks from the total price of 100
            if(hen+cock+chick==100)
            printf("%d\t%d\t%d\n",hen,cock,chick);
            
            /*another solution*/
            /*
            chick=100-cock-hen;   //The number of chicks is calculated by subtracting the number of hens and roosters from a total of 100
            if (chick%2==0 && hen*3+cock*2+chick/2==100)  //judging whether the number of chicks is a multiple of 2 is a must
            std::cout<<hen<<"\t\t"<<cock<<"\t\t"<<chick<<std::endl;
            */
        }
    }
    return 0;
}