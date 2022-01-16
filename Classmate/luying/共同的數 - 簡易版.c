#include <stdbool.h>
#include <stdio.h>
int main() {
    int n, m, i, j;
    int number1[200000], number2[200000];
    scanf("%d %d", &n, &m);
    for (; n > 0; n--) {
        bool had[200000] = {0};
        j = 0;
        for (i = 0; i < m; i++) {
            scanf("%d", &number1[i]);
            had[number1[i]] = 1;
        }
        for (i = 0; i < m; i++) {
            scanf("%d", &number2[i]);
            if (had[number2[i]]) j++;
        }
        printf("%d\n", j);
    }
    return 0;
}