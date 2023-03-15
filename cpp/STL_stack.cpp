//how to use stack
#include <bits/stdc++.h>
#define cout std::cout
#define endl std::endl

std::stack<int>st;

int main()
{
    st.push(114);//insert an element at the end
    st.push(514);
    cout<<st.top()<<endl;//the value of the last element
    if(!st.empty())//A boolean indicating whether the stack is empty
    cout<<st.size()<<endl;//the size of the stack
    st.pop();st.pop();// pop the last x
    if(!st.empty())
    cout<<st.size()<<endl;
    return 0;
}