#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;

class Palindrome{
public:
    void findLongestPalindrome(const std::string& input);
private:
    void expandAroundCenter(const std::string& s, int left, int right, int& start, int& maxLength, int &s_Length);
}palindromeFinder;

int main(){
    std::string input;
    cin >> input;
    palindromeFinder.findLongestPalindrome(input);
    return 0;
}

void Palindrome::findLongestPalindrome(const std::string& input){
        int n = input.length();
        if(n == 0){
            cout << 0 << endl;
            return;
        }

        int start = 0, maxLength = 1;
        for(int i = 0; i < n; i++){
            expandAroundCenter(input, i, i, start, maxLength, n);
            expandAroundCenter(input, i, i + 1, start, maxLength, n);
        }

        if(maxLength == 1)
            cout << 0 << endl;
        else
            cout << maxLength << endl
                 <<input.substr(start, maxLength) << endl;
        
    }

void Palindrome::expandAroundCenter(const std::string& s, int left, int right, int& start, int& maxLength, int &s_Length){
        int currentLength;
        while (left >= 0 && right < s_Length && s[left] == s[right]){
            currentLength = right - left + 1;
            if (currentLength > maxLength){
                start = left;
                maxLength = currentLength;
            }
            left--;
            right++;
        }
    }