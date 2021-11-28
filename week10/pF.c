#include <stdio.h>

int r[100] = {0}, ans = 0;
int n, a[100];
int c(int i, int s) {
    r[i] = 1;
    int cb = 0;
    for (int j = 0; j < n && !cb; j++) {
        for (int k = n - 1; k >= 0 && !cb; k--) {
            if (k == j || j == i || k == i) continue;
            if (a[j] + a[k] == a[i] && !r[j] && !r[k]) {
                r[j] = 1;
                r[k] = 1;
                for (int w = 0; w < n && !cb; w++)
                    if (!r[w])
                        if (s + 3 == n - 1) {
                            // printf("at i: %d\n", i);
                            // for (int g = 0; g < n; g++) {
                            //     printf("r[%d]:%d ", g, r[g]);
                            // }
                            return a[w];
                        }

                        else
                            cb |= c(w, s + 3);
                r[j] = 0;
                r[k] = 0;
            }
        }
    }
    r[i] = 0;
    return cb;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n; i >= 0 && !ans; i--)
        ans |= c(i, 0);
    printf("%d", ans);
}