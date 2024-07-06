#include <iostream>
#include <string>
#include <algorithm>
using std::cout; using std::endl; using::std::cin;
using std::string;

// 将字符串转为小写
std::string toLowerCase(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    string toReplace, replacement, line;
    std::getline(cin, toReplace);
    std::getline(cin, replacement);
    std::getline(cin, line);

    string lowerLine = toLowerCase(line);
    string lowerToReplace = toLowerCase(toReplace);

    string result;
    size_t pos = 0;
    size_t prevPos = 0;
    while ((pos = lowerLine.find(lowerToReplace, pos)) != string::npos) {
        result += line.substr(prevPos, pos - prevPos);
        result += replacement;
        pos += toReplace.length();
        prevPos = pos;
    }
    result += line.substr(prevPos);
    std::cout << result << std::endl;
    return 0;
}
