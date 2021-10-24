#include <stdio.h>
#include <stlib.h>
int main() {
    int i, min, max;
    min();
    int a[i];
    scanf("%d", &a[0]);
    min = max = a[0];
    for (int i = 1; i > 0; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    printf("%d %d", max, min);
    return 0;
}