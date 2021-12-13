#include <stdio.h>
#define N 500
#define swap(x, y)   \
    {                \
        int tmp = x; \
        x = y;       \
        y = tmp;     \
    }

void quicksort(int a[], int l, int h);
int partition(int a[], int l, int h);

int size;

int main(void) {
    int a[N];
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
void SWAP(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void quicksort(int a[], int l, int h) {
    if (l >= h) return;
    int s = l - 1;
    for (int i = l; i < h; i++)
        if (a[i] <= a[h])
            SWAP(&a[i], &a[++s]);
    SWAP(&a[h], &a[++s]);
    for (int i = 0; i < size; i++) {
        if (i == l)
            printf("[ ");
        if (i == s)
            printf("*");
        printf("%d ", array[i]);
        if (i == h)
            printf("] ");
    }
    printf("\n");
    quicksort(a, l, s - 1);
    quicksort(a, s + 1, h);
}

int partition(int a[], int l, int h) {
}