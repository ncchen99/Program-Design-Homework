#include <stdio.h>
#define N 500
#define swap(x, y)   \
    {                \
        int tmp = x; \
        x = y;       \
        y = tmp;     \
    }

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int size;

int main(void) {
    int array[N];
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

void quicksort(int array[], int low, int high) {
    int middle;
    if (low >= high) return;
    middle = partition(array, low, high);
    for (int i = 0; i < size; i++) {
        if (i == low)
            printf("[ ");
        if (i == middle)
            printf("*");
        printf("%d ", array[i]);
        if (i == high)
            printf("] ");
    }
    printf("\n");
    quicksort(array, low, middle - 1);
    quicksort(array, middle + 1, high);
}
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int swappoint = low - 1;
    for (;;) {
        if (low < high && array[low] <= pivot) {
            swappoint++;
            swap(array[low], array[swappoint]);
        }
        low++;
        if (low == high) break;
    }
    swappoint++;
    swap(array[high], array[swappoint]);
    return swappoint;
}