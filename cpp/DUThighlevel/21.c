#include <stdio.h>

int main() {
    int n;
    int i;
    long long stranger_total = 0;
    long long millionaire_total = 0;
    long long current_payment = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        stranger_total += 100000;
        millionaire_total += current_payment;
        current_payment *= 2; 
    }

    printf("%lld\n", stranger_total);
    printf("%lld\n", millionaire_total);

    return 0;
}
