#include <stdio.h>
#include <string.h>
int cmp(char *a, char *b) {
    return *a - *b;
}

int p(char *a, int r[], char *ans, int d) {
    if (d == strlen(a))
        printf("%s\n", ans);
    for (int i = 0; i < strlen(a); i++) {
        if (!r[i]) {
            r[i] = 1;
            ans[d] = a[i];
            p(a, r, ans, d + 1);
            r[i] = 0;
        }
    }
}
int main() {
    char a[10000] = {};
    int r[10000] = {};
    scanf("%s", a);
    qsort(a, strlen(a), 1, cmp);
    char ans[10000] = {};
    p(a, r, ans, 0);
}