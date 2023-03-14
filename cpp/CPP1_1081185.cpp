#include <iostream>

int main()
{
    int num;
    std::cout << "输入任意一个3位正整数: ";
    std::cin >> num;
    int a = num / 100;
    int b = (num / 10) % 10;
    int c = num % 10;
    int result = c * 100 + b * 10 + a;
    std::cout << "输入的3位正整数的逆序数: " << result << std::endl;
    return 0;
}