#include <stdio.h>
#include <string.h>
int main() {
    char k[10000] = {0}, p[200000] = {0};
    gets(k);
    gets(p);
    for (int i = 0; i < strlen(p); i++)
        printf("%c", k[i % strlen(k)] ^ p[i]);
}