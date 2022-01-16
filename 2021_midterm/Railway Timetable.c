#include <stdio.h>
int main() {
    int h, m, n, minx = 1e9, mint = 1e9;
    scanf("%d:%d\n%d", &h, &m, &n);
    for (int i = 0; i < n; i++) {
        int x, H, M, y;
        scanf("%d %d:%d %d", &x, &H, &M, &y);
        int ttime = 60 * H + M;
        if (ttime >= h * 60 + m)
            if (mint > ttime + y) {
                mint = ttime + y;
                minx = x;
            }
    }
    printf("%d", minx);
}