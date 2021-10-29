#include <stdio.h>
#include <stdlib.h>
#define f(u, s, n, a)             \
    for (int u = s; u < n; u++) { \
        a;                        \
    }
int main() {
    long long n, prev1 = 1, prev2 = 0, ans = 0;
    scanf("%lld", &n);
    f(i, 0, n / 10, ans = prev1 + prev2; prev2 = prev1; prev1 = ans;);
    printf("%lld", ans);
}