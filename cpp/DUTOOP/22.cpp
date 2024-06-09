#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;

class FactorialSumNumber {
private:
    int number;
    int digits[10];
    int digitCount;
    int factorialSum;
    
    int factorial(int n);
    void calculateFactorialSum();
public:
    FactorialSumNumber(int num);
    void outputResult();
};

int main() {
    int inputNumber;
    cin >> inputNumber;
    FactorialSumNumber factorialsumnumber(inputNumber);
    factorialsumnumber.outputResult();

    return 0;
}


FactorialSumNumber::FactorialSumNumber(int num) : number(num), digitCount(0), factorialSum(0) {
    while (num > 0) {
        digits[digitCount++] = num % 10;
        num /= 10;
    }
    calculateFactorialSum();
}

int FactorialSumNumber::factorial(int n){
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

void FactorialSumNumber::calculateFactorialSum(){
    factorialSum = 0;
    for (int i = 0; i < digitCount; ++i)
        factorialSum += factorial(digits[i]);
}

void FactorialSumNumber::outputResult() {
    cout << number << ",";
    for (int i = digitCount - 1; i >= 0; --i) {
        cout << digits[i] << "!";
        if (i != 0)
            cout << "+";
    }
    cout << "=" << factorialSum << endl;
    if (factorialSum == number)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    
}