#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(int* a, int* b) {
    return *a > *b;
}
int main() {
    int n, a[100] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        int tmp[100] = {}, r[100] = {}, h = 0, ans;
        for (int x = 0; x < n - 1; x += 3)
            for (int k = 0; k < n; k++)
                for (int j = 0; j < n; j++)
                    for (int w = 0; w < n; w++)
                        if (a[k] + a[j] == a[w] && k != j && j != w && k != w && !r[k] && !r[w] && !r[j]) {
                            r[k] = 1;
                            r[j] = 1;
                            r[w] = 1;
                            j = n;
                            k = n;
                            break;
                        }
        for (int w = 0; w < n; w++)
            if (!r[w]) {
                h++;
                ans = a[w];
            }
        if (h == 1) {
            printf("%d", ans);
            break;
        }
        for (int k = 0; k < n - 1; k++)
            tmp[k] = a[(k + 1) % n];
        tmp[n - 1] = a[0];
        memcpy(a, tmp, sizeof(int) * n);
    }
}