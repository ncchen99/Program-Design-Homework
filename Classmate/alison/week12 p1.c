#include <stdio.h>
#include <string.h>
char *mystrcat(char *dest, char *src) {
    strcat(dest, src);
    return dest;
}

char *mystrncat(char *dest, char *src, int n) {
    strncat(dest, src, n);
    return dest;
}

int main() {
    char a[100] = "  non e ", b[500] = "fwefwewewf";
    printf("%s\n", mystrcat(a, b));
    printf("%s\n", mystrncat(a, b, 5));
}
