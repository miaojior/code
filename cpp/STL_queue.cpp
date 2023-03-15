#include <bits/stdc++.h>
#define cout std::cout
#define endl std::endl

int main()
{
    std::queue<int>que;
    que.push(114);
    que.push(514);
    cout<<que.front()<<endl;
    if(!que.empty())//A boolean indicating whether the queue is empty
    cout<<que.back()<<endl;//the last element of the queue
    cout<<que.size()<<endl;//thr size of the queue
    que.pop();que.pop();//
    return 0;
}