#include <stdio.h>

int main() {
    unsigned long long int m, m2, n, i = 1, result;
    __uint128_t s = 1, p = 1;

    do {
        scanf("%llu %llu", &m, &n);
    } while (n < 1 || m < n || 30 <= m);

    m2 = m;
    if (m != n) {
        while (m2 > n) {
            s *= m2;
            --m2;
        }
        while (i <= (m - n)) {
            p *= i;
            ++i;
        }
        result = s / p;
    } else
        result = 0;

    printf("%llu", result);
    return 0;
}