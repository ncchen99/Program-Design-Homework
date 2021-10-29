#include <stdio.h>
#include <stdlib.h>
#define f(u, s, n, a)             \
    for (int u = s; u < n; u++) { \
        a;                        \
    }
int main() {
    int a[10], maxN = -1e9;

    f(i, 0, 10, scanf("%d", &a[i]));
    f(i, 0, 10, f(
                    j, 0, 10, if (i != j) { maxN = (maxN < abs(i - j) * (a[i] + a[j]) ? abs(i - j) * (a[i] + a[j]) : maxN); }));
    printf("%d", maxN);
}