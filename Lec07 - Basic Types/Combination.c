#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define f(u, s, n, a)             \
    for (int u = s; u < n; u++) { \
        a;                        \
    }
#define int __uint128_t
#define ull unsigned long long

char *sprintf_int128(int n) {
    static char str[41] = {0};
    char *s = str + sizeof(str) - 1;  // 指向末端的指標
    for (; n; n /= 10)
        *--s = "0123456789"[n % 10];
    return s;
}

int fa(int n) {
    int t = n;
    f(i, 1, n, t *= (int)i);
    return t;
}

int32_t main() {
    long long m, n;
    __uint128_t a;
    scanf("%lld%lld", &m, &n);
    printf("%lld", (long long)a);
}