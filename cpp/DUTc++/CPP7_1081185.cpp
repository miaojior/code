#include <iostream>

    const int N=20;
    int num,pos_nums[N],neg_num=0,sum_neg=0;

int main(){
    //read input
    std::cout<<"输入任意20个整数（空格键隔开）：";
    for(int i=0;i<N;i++)
    {
        std::cin>>num;
        if(num<0)
            neg_num++,sum_neg+=num;
        else
            pos_nums[i-neg_num]=num;
    }
    std::cout<<" 输入结束！"<<std::endl;

    //bubble sort
    for(int i=0;i<N-neg_num;i++)
    for (int j=N-neg_num-1;j>i;j--)
        if (pos_nums[j]<pos_nums[j - 1])
            std::swap(pos_nums[j],pos_nums[j - 1]);

    //output
    std::cout<<"负数个数："<<neg_num<<std::endl<<"负数之和："<<sum_neg<<std::endl;
    std::cout<<"正数排序后输出：";
    for (int i=0;i<N-neg_num-1;i++)
        std::cout<<pos_nums[i]<<" ";
    std::cout<<pos_nums[N-neg_num-1]<<std::endl;
    return 0;
}