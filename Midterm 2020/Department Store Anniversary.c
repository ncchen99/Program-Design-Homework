#include <stdio.h>
int main() {
    int m, n;
    int a[1001], b[1001];
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int ai = 0, bi = 0;
    for (int i = 0; i < n + m; i++) {
        if (!a[ai]) a[ai] = 10005;
        if (!b[bi]) b[bi] = 10005;
        if (a[ai] < b[bi])
            printf("%d ", a[ai++]);
        else
            printf("%d ", b[bi++]);
    }
}
// 3 7
// 1 8 9
// 2 5 7 11 16 17 21
