#include <stdio.h>
#include <stdlib.h>
int cmp(int *a, int *b) {
    return *a > *b;
}
int merger(int *a, int *b, int *c) {
    for (int i = 0; i < 5; i++) {
        c[i] = a[i];
        c[5 + i] = b[i];
    }
    qsort(c, 10, sizeof(c[0]), cmp);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int res[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    merger(arr, arr + 5, res);
    for (int i = 0; i < 10; i++)
        printf("%d ", res[i]);
}