#include <iostream>

int main()
{
    int num;
    std::cout << "��������һ��3λ������: ";
    std::cin >> num;
    int a = num / 100;
    int b = (num / 10) % 10;
    int c = num % 10;
    int result = c * 100 + b * 10 + a;
    std::cout << "�����3λ��������������: " << result << std::endl;
    return 0;
}