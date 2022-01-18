#include <stdio.h>
#include <string.h>
char *trim(char *dest) {
    while (*dest == '\n' || *dest == '\t' || *dest == ' ') {
        *dest = '\0';
        dest++;
    }

    char *end = dest + strlen(dest) - 1;
    while (*end == '\n' || *end == '\t' || *end == ' ') {
        *end = '\0';
        end--;
    }
    return dest;
}

int main() {
    char a[100] = "  non e ";
    printf("%s", trim(a));
}
