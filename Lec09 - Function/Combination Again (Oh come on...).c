#include <stdio.h>

int c(int n, int m) {
    if (m == 0 || m == n)
        return 1;
    return c(n - 1, m - 1) + c(n - 1, m);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", c(n, m));
}