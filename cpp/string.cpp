#include <iostream>
#include <string>
using namespace std;


int main(){
  string s1,s2;
  s1=s2="abc";  
  cout<<s1<<endl;
  s1=s2+"abc";   
  cout<<s1<<endl;
  s1.append(s2);
  cout<<s1<<endl;
  cout<<s1.length()<<endl;
  cout<<s1.empty()<<endl;
  s1.replace(3,3,"defgh");
  cout<<s1<<endl;
  cout<<s1.find("gh")<<endl;
	cout<<(int)s1.find("cba")<<endl;
  cout<<s2.compare("abc")<<endl;
  cout<<s2.compare("abe")<<endl;
  cout<<s2.compare("aba")<<endl;
}
