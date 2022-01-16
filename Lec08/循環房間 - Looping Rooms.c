#include <stdio.h>
#include <stdlib.h>
#define f(u, s, n, a)             \
    for (int u = s; u < n; u++) { \
        a;                        \
    }
int n, p[1000], a[1000], rn = 0;  // path ,ancestor
int dfs(int n, int prt) {
    if (a[n] == -1) {
        a[n] = prt;
        dfs(p[n], prt);
    }
    if (a[n] == prt)
        return 1;
    if (a[n] != -1)
        return 0;
}
int main() {
    scanf("%d", &n);
    f(i, 0, n, scanf("%d", &p[i]); a[i] = -1;);
    f(i, 0, n, rn += dfs(i, i););
    printf("%d rings\n", rn);
    f(
        i, 0, n,
        if (a[i] != -1) {
            a[i] = -1;
            printf("%d ", i);
            int c;
            for (c = p[i]; c != i; a[c] = -1, c = p[c])
                printf("-> %d ", c);
            printf("-> %d\n", c);
        });
}