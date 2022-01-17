#include <stdio.h>
#include <stdlib.h>
short* calc(short a[], int len) {
    if (len == 1)
        return a;
    int sume = 0, sumo = 0;
    for (int i = 0; i < len; i++) {
        if (i & 1)
            sume += a[i];
        else
            sumo += a[i];
    }
    short oa[100] = {};
    short ea[100] = {};
    int lene = 1, leno = 1, i, j, sumeb = sume, sumob = sumo;
    for (; sumeb / 16; sumeb /= 16)
        lene++;
    for (; sumob / 16; sumob /= 16)
        leno++;
    for (i = lene - 1; i >= 0; i--, sume /= 16)
        ea[i] = sume % 16;
    for (i = leno - 1; i >= 0; i--, sumo /= 16)
        oa[i] = sumo % 16;

    ea[lene] = -1;
    oa[leno] = -1;
    short* e = calc(ea, lene);
    short* o = calc(oa, leno);

    short* c = malloc(sizeof(short) * 200);
    for (i = 0;; i++) {
        if (e[i] == -1)
            break;
        c[i] = e[i];
    }
    for (j = i;; j++) {
        if (o[j - i] == -1)
            break;
        c[j] = o[j - i];
    }
    c[j] = -1;
    return c;
    free(e);
    free(o);
}
int main() {
    short a[20000] = {}, i = 0, tmp = 0;
    while (scanf("%1x", &a[i++]) != EOF) {
    }
    i--;
    short* ans = calc(a, i);
    for (int i = 0;; i++)
        if (ans[i] == -1)
            break;
        else
            printf("%x", ans[i]);
}