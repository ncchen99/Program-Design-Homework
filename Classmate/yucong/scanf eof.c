#include <stdio.h>
int main() {
    char str[10000], ch;
    int i = 0;
    while ((ch = getchar()) != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';
    printf("%s", str);
}