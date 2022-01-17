#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu {
    char o[120];
    char m[120];
} Stu;
int cmp(const void* a, const void* b) {
    char *aa = ((Stu*)a)->m, *bb = ((Stu*)b)->m;
    return strcmp(aa, bb);
}
int main() {
    Stu s[130];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i].o);
        for (int k = 0; k < strlen(s[i].o); k++)
            s[i].m[k] = tolower(s[i].o[k]);
    }
    qsort(s, n, sizeof(s[0]), cmp);
    for (int i = 0; i < n; i++)
        printf("%s\n", s[i].o);
    return 0;
}
