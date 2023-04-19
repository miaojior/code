#include <iostream>

const int N=20;
int num,pos_nums[N],neg_num=0,sum_neg=0,lastswap,flag,currentupperlimit;

int main(){
    //read input
    std::cout<<"输入任意20个整数（空格键隔开）：";
    for(int i=0;i<N;i++){
        std::cin>>num;
        if(num<0)
            neg_num++,sum_neg+=num;
        else
            pos_nums[i-neg_num]=num;
    }
    std::cout<<" 输入结束！"<<std::endl;

    //bubble sort
    lastswap=N-neg_num;
    for(int i=0;i<N-neg_num;i++)
    {   
        currentupperlimit=lastswap;
        lastswap=0;
        for(int j=1;j<currentupperlimit;j++){ //a traversal is enough to break, when traversing to the last position where the last swap happened in the previous traversal
            if(pos_nums[j]<pos_nums[j - 1]){
                std::swap(pos_nums[j],pos_nums[j-1]);
                lastswap=j;
            }
        }
        if(!lastswap)//If a traversal does not have any swaps, it's time to break!!!
        break;
    }

    //output
    std::cout<<"负数个数："<<neg_num<<std::endl<<"负数之和："<<sum_neg<<std::endl;
    std::cout<<"正数排序后输出：";
    for (int i=0;i<N-neg_num-1;i++)
        std::cout<<pos_nums[i]<<" ";
    std::cout<<pos_nums[N-neg_num-1]<<std::endl;
    return 0;
}