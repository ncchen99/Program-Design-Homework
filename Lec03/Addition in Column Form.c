#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("  %04d\n+)%04d\n------\n%06d", a, b, a + b);
}