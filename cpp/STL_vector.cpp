//how to use vector
#include <bits/stdc++.h>
#define cout std::cout
#define endl std::endl

int main()
{
    std::vector<int>vec;
    vec.push_back(114);//insert an element at the end.  vec[0]=2
    vec.push_back(514);//vec[1]=4
    
    *vec.end()=1919810;// the pointer of the next position of the last vector element(could not used to push back elements , because in this way the size wouldn't increase)
    cout << vec[2]<<endl;
    cout<<*vec.begin()<<endl;//the pointor of the fist vector element
    cout<<vec.size()<<endl;//the size of vector
    
    cout << vec[2]<<endl;
    //Traversing using array subscripts
    for(int i=0;i<vec.size()+1;i++)
    cout<<vec[i]<<" ";
    cout<<endl;
    vec.resize(3);// change the size of vector (undefined elements , determined by the previous size ,will be automatically filled with zeros)
    //Traversing using array iterator
    std::vector<int>::iterator it;
    for (it=vec.begin(); it!=vec.end(); ++it)
    cout<<*it<<" ";
    cout<<endl;

    
    vec.insert(vec.begin()+1,6);//insert element"6" to the second position of vectro
    vec.erase(vec.begin()+2);//erase the third element in the vector
    for (it=vec.begin(); it!=vec.end(); ++it)
    cout<<*it<<" ";
    cout<<endl;

    if(!vec.empty())//A boolean indicating whether the vector is empty
    {
        vec.clear(); //clear all the elements in vector
        cout<<"cleared!"<<endl;
    }

    int m,n;//size of array
    //two-dimensional array defined by vector
    std::vector<std::vector<int>>array(m);
    for(int i=0;i<m;i++)
    array[i].resize(n);
    int i,j;//subscripts of the array
    array[i][j];//the element in row i and column j
    return 0; 
}

//notes written by miaojior , personal understanding ,not guaranteed to be all correct
/*
sample output
1919810
114
2
1919810
114 514 1919810 
114 514 0 
114 6 0 
cleared!
*/