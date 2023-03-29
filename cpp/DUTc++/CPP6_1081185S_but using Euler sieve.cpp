#include <iostream>

const int N = 100000010;
int primes[N],m,cnt;
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)break;
        }
    }
}

int main() {
    std::cout << "输入任意一个正整数: ";
    std::cin >> m;
    get_primes(m);
    for (int i = 0; primes[i] <= m / 2; ++i) {
        if (!st[m - primes[i]]) {
            std::cout << "能写成两个素数之和，两个素数是：" << primes[i] << "和" << m - primes[i] << std::endl;
            return 0;
        }
    }
    std::cout << "不能写成两个素数之和" << std::endl;
    return 0;
}