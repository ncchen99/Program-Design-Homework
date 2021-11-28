#include <stdio.h>
#include <stdlib.h>

typedef struct Class {
    int s;
    int e;
} class;

int cmp(class* a, class* b) {
    return (*a).e > (*b).e;
}

int main() {
    int n;
    class c[100005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int d, s, e;
        scanf("%d%d%d", &d, &s, &e);
        c[i].s = d * 10 + s;
        c[i].e = d * 10 + e;
    }

    // 使用 qsort 排序
    qsort(c, n, sizeof(c[0]), cmp);

    // for (int i = 0; i < n; i++) {
    //     printf("c[%d] s=%d, e =%d\n", i, c[i].s, c[i].e);
    // }
    int e = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (c[i].s >= e) {
            // printf("choose: c[%d]\n", i);
            ans++;
            e = c[i].e;
        }
    }
    printf("%d\n", ans);
}