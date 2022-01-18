#include <stdio.h>
#include <string.h>

char *replace(char *source, char *pattern, char *replacement) {
    char *l = strstr(source, pattern);
    while (l != NULL) {
        l += strlen(pattern);
        char tmp[100000];
        strcpy(tmp, l);
        strcpy(l - strlen(pattern), replacement);
        strcpy(l - strlen(pattern) + strlen(replacement), tmp);
        break;
        l = strstr(l + strlen(replacement), pattern);
    }
    return source;
}
char *replaceAll(char *source, char *pattern, char *replacement) {
    char *l = strstr(source, pattern);
    while (l != NULL) {
        l += strlen(pattern);
        char tmp[100000];
        strcpy(tmp, l);
        strcpy(l - strlen(pattern), replacement);
        strcpy(l - strlen(pattern) + strlen(replacement), tmp);
        l = strstr(l + strlen(replacement), pattern);
    }
    return source;
}

int main() {
    char a[100000] = "abbabdfefwebbojhbbfee", b[1000] = "bb", c[1000] = "FF";
    printf("%s\n", replaceAll(a, b, c));
    // printf("%s\n", replace(a, b, c));
}