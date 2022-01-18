#include <stdio.h>
#include <string.h>
int main() {
    char a[100000] = {};
    gets(a);
    char *l = strtok(a, " ");
    char b[1000][100] = {};
    int idx = 0;
    while (l != NULL) {
        strcpy(b[idx++], l);
        l = strtok(NULL, " ");
    }
    for (int i = idx - 1; i >= 0; i--) {
        printf("%s ", b[i]);
    }
}