#include <stdio.h>
#include <string.h>

int main() {
    unsigned a, b;
    scanf("%x %x", &a, &b);
    if (a + b > 0xFFFF)
        printf("OVERFLOW!");
    else
        printf("%d", a + b);
}