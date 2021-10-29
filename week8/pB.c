#include <stdio.h>
#include <stdlib.h>
#define f(u, s, n, a)             \
    for (int u = s; u < n; u++) { \
        a;                        \
    }
int main() {
    int a[300] = {}, n, tmp;
    scanf("%d", &n);
    f(i, 0, n, char p; scanf("%d %c", &tmp, &p); a[p] = tmp;);
    f(i, 'A', 'Z' + 1, if (a[i]) printf("Plan %c is in box %d.\n", i, a[i]); else printf("Not found plan %c.\n", i););
}