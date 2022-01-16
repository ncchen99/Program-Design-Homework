#include <assert.h>
#include <stdio.h>
#include <string.h>
int main() {
    long a, b = 0;
    long a_6 = 0, tmp;
    char q;
    int jud, k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &jud);
        switch (jud) {
            case 8:
                scanf(" %lo", &a);
                break;
            case 6:
                getchar();
                while (1) {
                    q = getchar();
                    if (q == '\n' || q == EOF) break;
                    // printf("%c", q);
                    // assert('0' <= q && q <= '6');
                    if (q >= '0' && q <= '6') {
                        q -= 48;
                        a_6 *= 6;
                        a_6 += q;
                    }
                }
                a = a_6;
                a_6 = 0;
                break;
            case 16:
                scanf(" %lx", &a);
                break;
            case 10:
                scanf(" %ld", &a);
        }
        b += a;
        b %= 1000000007;
    }
    printf("%ld", b);
}
