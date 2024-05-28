#include <iostream>
#include <cmath>
using std::cin; using std::cout; using std::endl;

class primeSieve {
private:
    int n;
    bool isPrime[2000010];
public:
    primeSieve(int num);
    ~primeSieve();
    void sieve();
    void print();
};

int main() {
    int num;
    cin >> num;
    primeSieve prime(num);
    prime.sieve();
    prime.print();
    return 0;
}


primeSieve::primeSieve(int num) : n(num){
    for (int i = 0; i <= n; ++i)
        isPrime[i] = true;
}

primeSieve::~primeSieve(){
    ;
}

void primeSieve::sieve(){
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
}

void primeSieve::print(){
    for (int i = 2; i <= n; ++i) 
        if (isPrime[i])
            cout << i << ' ';
}