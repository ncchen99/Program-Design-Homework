#include <stdio.h>

int main() {
    int m, n, i, num = 0;
    int p[200], c[200];
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++) {
        scanf("%d%d", &p[i], &c[i]);
    }
    for (int j = 0; j < m - 1; j++) {
        for (i = 0; i < m - 1; i++) {
            if (p[i] > p[i + 1]) {
                int temp = p[i];
                p[i] = p[i + 1];
                p[i + 1] = temp;

                int a = c[i];
                c[i] = c[i + 1];
                c[i + 1] = a;
            }
        }
    }
    if (n < c[0])
        printf("%d", n * p[0]);
    else {
        for (i = 0; n > c[i]; i++) {
            n -= c[i];
            num += c[i] * p[i];
        }
        num += n * p[i];
        printf("%d", num);
    }
    return 0;
}

/*
5 11
100 2
90 2
80 2
70 5
60 5
*/