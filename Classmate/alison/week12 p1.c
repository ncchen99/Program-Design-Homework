#include <stdio.h>
#include <string.h>
char *mystrcat(char *dest, char *src) {
    for (char *c = dest + strlen(dest), *b = src; *b != '\0'; b++, c++)
        *c = *b;
    dest[strlen(dest) + strlen(src)] = '\0';
    return dest;
}

char *mystrncat(char *dest, char *src, int n) {
    int i = 0;
    for (char *c = dest + strlen(dest), *b = src; i < n && *b != '\0'; b++, c++, i++)
        *c = *b;
    dest[strlen(dest) + n] = '\0';
    return dest;
}

int main() {
    char a[100] = "  non e ", b[500] = "fwefwewewf";
    printf("%s\n", mystrcat(a, b));
    printf("%s\n", mystrncat(a, b, 5));
}
