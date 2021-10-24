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
                do {
                    q = getchar();
                    if (q >= '0' && q <= '6') {
                        q -= 48;
                        a_6 *= 6;
                        a_6 += q;
                    }
                } while (q != '\n' && q != EOF);
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
