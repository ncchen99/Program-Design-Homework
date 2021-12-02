#include <stdio.h>
#include <string.h>
int main() {
    int b, w, t, g, m, s, i;
    int sn, e = 0;
    scanf("%d%d%d%d%d%d%d \n%d\n", &b, &w, &t, &g, &m, &s, &i, &sn);
    b = b * 1000;
    w = w * 1000;
    t = t * 1000;
    g = g * 1000;
    m = m * 1000;
    s = s * 1000;
    i = i * 1000;
    for (; sn--;) {
        char c[5];
        int ss, is;
        scanf("%s %d/%d\n", c, &ss, &is);
        if (!strcmp(c, "G")) {
            g -= 500;
            e += 20;
        }
        if (!strcmp(c, "B")) {
            b -= 500;
            e += 20;
        }
        if (!strcmp(c, "T")) {
            t -= 500;
            e += 30;
        }
        if (!strcmp(c, "W")) {
            w -= 500;
            e += 15;
        }
        if (!strcmp(c, "GT")) {
            t -= 250;
            g -= 250;
            e += 45;
        }
        if (!strcmp(c, "WT")) {
            t -= 350;
            w -= 150;
            e += 40;
        }
        if (!strcmp(c, "BM")) {
            b -= 200;
            m -= 300;
            e += 35;
        }
        if (!strcmp(c, "TM")) {
            t -= 200;
            m -= 300;
            e += 45;
        }
        if (!strcmp(c, "WM")) {
            w -= 200;
            m -= 300;
            e += 30;
        }
        int st[5] = {0, 3, 5, 7, 10}, it[5] = {0, 30, 50, 70, 100};
        s -= st[ss - 1];
        i -= it[is - 1];
    }
    printf("%d %d %d %d %d %d %d\n%d\n", b, w, t, g, m, s, i, e);
    return 0;
}
