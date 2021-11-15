#include <stdbool.h>
#include <stdio.h>
#define maxn 50001
int main() {
    int n, num;
    scanf("%d", &n);
    int a[maxn];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bool b[maxn] = {0};
    // for (int i = 0; i < n; i++) {
    //     b[i] = false;
    // }
    num = 0;
    for (int i = 0; i < n; i++) {
        int now = i;
        if (!b[now]) {
            while (!b[now]) {
                b[now] = true;
                now = a[now];
            }
            num++;
        }
    }
    printf("%d rings\n", num);

    bool c[n];
    for (int i = 0; i < n; i++) {
        c[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int now = i;
        if (!c[now]) {
            while (!c[now]) {
                printf("%d -> ", now);
                c[now] = true;
                now = a[now];
            }
            printf("%d\n", now);
        }
    }
    return 0;
}