#include <stdio.h>
#include <string.h>
void add(char a[], char b[], char res[]);

int main() {
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

void add(char a[], char b[], char res[]) {
    short c[101] = {}, d[101] = {}, r[106] = {};
    for (int i = strlen(a) - 1, k = 0; i >= 0; i--)
        c[k++] = a[i] - '0';
    for (int i = strlen(b) - 1, k = 0; i >= 0; i--)
        d[k++] = b[i] - '0';
    int i = 0, w = 0;
    for (; i < (strlen(a) > strlen(b) ? strlen(a) : strlen(b)); i++) {
        r[i + 1] = (c[i] + d[i] + r[i]) / 10;
        r[i] = (c[i] + d[i] + r[i]) % 10;
    }
    for (int k = (r[i] == 0 ? i - 1 : i); k >= 0; k--, w++)
        res[w] = '0' + r[k];
    res[w] = '\0';
}