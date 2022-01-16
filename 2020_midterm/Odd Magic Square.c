#include <stdio.h>
int main() {
    int n, s[52][52] = {0};
    scanf("%d", &n);
    int ni = 0, nj = n / 2;
    for (int k = 1; k <= n * n;) {
        s[ni][nj] = k++;
        int oi = ni, oj = nj;
        ni = (ni == 0 ? n - 1 : ni - 1);
        nj = (nj + 1 == n ? 0 : nj + 1);
        if (s[ni][nj] == 0)
            continue;
        else {
            ni = (oi + 1 == n ? 0 : oi + 1);
            nj = oj;
            continue;
        }
    }
    for (int i = 0; i < n; i++, printf("\n"))
        for (int j = 0; j < n; j++)
            printf("%d ", s[i][j]);
}