#include <stdio.h>
int elementAt(int* pointer, int n) {
    return *(pointer + n - 1);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d", elementAt(arr, 5));
}