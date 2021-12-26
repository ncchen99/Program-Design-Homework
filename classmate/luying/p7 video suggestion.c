#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define eps 0.000000009
typedef struct data {
    char name[1000];
    int p, l, w, r;
    double recommend;
} Data;

int cmp(const void* a, const void* b) {
    if (((Data*)b)->recommend > ((Data*)a)->recommend)
        return 1;
    else
        return -1;
}
int main() {
    int n;
    scanf("%d", &n);
    Data youtuber[50];
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d%d%d", youtuber[i].name, &youtuber[i].p, &youtuber[i].l, &youtuber[i].w, &youtuber[i].r);
        youtuber[i].recommend = (double)(youtuber[i].p) * ((double)(youtuber[i].w) / (double)(youtuber[i].l)) * (double)(youtuber[i].r);
    }
    qsort(youtuber, n, sizeof(struct data), cmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", youtuber[i].name);
    }
}