#include <iostream>
using namespace std;

class ArmstrongFinder{
private:
    int a, b;
    bool isArmstrong(int num);
public:
    ArmstrongFinder(int start, int end);
    bool isValid();
    void findAndPrint();
};

int main(){
    int a, b;
    cin >> a >> b;
    ArmstrongFinder finder(a, b);
    if(!finder.isValid())
        return 0;
    finder.findAndPrint();
    return 0;
}


ArmstrongFinder::ArmstrongFinder(int start, int end) : a(start), b(end) {}

bool ArmstrongFinder::isValid(){
    if(a <= 0 || b <= 0 || a > b ){
        cout << "error" << endl;
        return false;
    }
    return true;
}

void ArmstrongFinder::findAndPrint(){
        bool found = false;
        for (int i = a; i <= b; ++i)
            if (isArmstrong(i)) {
                cout << i << endl;
                found = true;
            }
        if (!found)
            cout << "no" << endl;
}

bool ArmstrongFinder::isArmstrong(int num) {
    int original = num;
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit * digit;
        num /= 10;
    }
    return sum == original;
}