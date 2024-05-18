#include <iostream>
#include <string>

using namespace std;

class PalindromeFinder {
private:                                                                                                                                                                           
    string input;
    int maxLength;
    string longestPalindrome;
    void expandAroundCenter(int left, int right) {
        while (left >= 0 && right < input.length() && input[left] == input[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                longestPalindrome = input.substr(left, maxLength);
            }
            left--;
            right++;
        }
    }

public:
    PalindromeFinder(string str) {
        input = str;
        maxLength = 0;
        longestPalindrome = "";
    }

    void findLongestPalindrome() {
        for (int i = 0; i < input.length(); ++i) {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i + 1);
        }
    }
    void printLongestPalindrome() {
        if (maxLength > 0) {
            cout << maxLength << endl;
            cout << longestPalindrome << endl;
        } else {
            cout << "0" << endl;
        }
    }
};

int main() {
    string inputStr;
    getline(cin, inputStr);

    PalindromeFinder finder(inputStr);
    finder.findLongestPalindrome();
    finder.printLongestPalindrome();

    return 0;
}