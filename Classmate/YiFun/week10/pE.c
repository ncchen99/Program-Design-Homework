#include <stdio.h>
int c, l, a[40000] = {}, r[40000] = {}, p[40000] = {1, 1}, n = 1;
int lc(int a) {
    return a * 2;
}
int rc(int a) {
    return a * 2 + 1;
}

int pre(int n) {
    while (1) {
        if (n == 1 && r[n] >= 2)
            break;
        if (!r[n]++)
            printf("%d ", a[n]);
        if (a[lc(n)] && !r[lc(n)])
            n = lc(n);
        else if (a[rc(n)] && !r[rc(n)])
            n = rc(n);
        else
            n = p[n];
    }
}

int in(int n) {
    while (1) {
        if (r[n]++ == 1)
            printf("%d ", a[n]);
        if (n == 1 && r[n] > 2)
            break;
        if (a[lc(n)] && !r[lc(n)])
            n = lc(n);
        else if (a[rc(n)] && !r[rc(n)])
            n = rc(n);
        else {
            if (r[n] == 1)
                printf("%d ", a[n]);
            r[n] = 3;
            n = p[n];
        }
    }
}

int post(int n) {
    while (1) {
        if (n == 1 && r[n] > 2)
            break;
        r[n]++;
        if (a[lc(n)] && !r[lc(n)])
            n = lc(n);
        else if (a[rc(n)] && !r[rc(n)])
            n = rc(n);
        else {
            printf("%d ", a[n]);
            n = p[n];
        }
    }
}
int main() {
    scanf("%d%d", &c, &l);
    for (int i = 1; i <= l; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= l; i++) {
        p[i * 2 + 1] = i;
        p[i * 2] = i;
    }
    if (c == 0)
        pre(1);
    if (c == 1)
        in(1);
    if (c == 2)
        post(1);
}