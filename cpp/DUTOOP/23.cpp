#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using std::cin; using std::cout; using std::endl;
using std::string;

struct CharFreq {
public:
    char character;
    int freq;
    bool operator<(const CharFreq& other) const {
        return freq > other.freq;
    }
};

class Histogram {
private:
    int frequency[26];
    int maxFreq;
public:
    Histogram();
    void readInput();
    void printHistogram();
};

int main() {
    Histogram hist;
    hist.readInput();
    hist.printHistogram();
    return 0;
}

Histogram::Histogram() : maxFreq(0){
    memset(frequency, 0, sizeof(frequency));
}

void Histogram::readInput() {
    string input, line;
    while (std::getline(cin, line))
        input += line + "\n";
    for (char c : input)
        if(islower(c))
            frequency[c - 'a']++;
    for (int i = 0; i < 26; ++i)
        if (frequency[i] > maxFreq)
            maxFreq = frequency[i];
}

void Histogram::printHistogram(){
    CharFreq charFreq[26];
    for (int i = 0; i < 26; ++i){
        charFreq[i].character = 'a' + i;
        charFreq[i].freq = frequency[i];
    }
    std::sort(charFreq, charFreq + 26);
    for (int row = maxFreq; row > 0; --row){
        for (int i = 0; i < 26 && charFreq[i].freq > 0; ++i) 
            if (charFreq[i].freq >= row) 
                cout << '#';
            else 
                cout << ' ';
        cout << endl;
    }
}