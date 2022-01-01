#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b);
int n, m;
struct data {
    int number[201];
} line[100000];
int main() {
    scanf("%d %d", &n, &m);
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf("%d", &line[i].number[j]);
        }
    }
    qsort(line, n, sizeof(line[0]), cmp);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            printf("%d ", line[i].number[j]);
        }
        printf("\n");
    }
    return 0;
}
int cmp(const void *a, const void *b) {
    int j;
    int *an = (*(struct data *)a).number;
    int *bn = (*(struct data *)b).number;
    for (j = 0; j < m; ++j) {
        if (an[j] == bn[j])
            continue;
        else
            return an[j] - bn[j];
    }
}