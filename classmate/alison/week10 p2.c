#include <stdio.h>

int between(int* a, int* b) {
    int sum = 0;
    for (int* i = a; i < b; i++) {
        sum += *i;
    }
    return sum;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("%d", between(arr, arr + 5));
}