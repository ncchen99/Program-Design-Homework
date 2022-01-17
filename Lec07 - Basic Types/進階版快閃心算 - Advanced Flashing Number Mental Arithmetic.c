#include <stdio.h>
#include <string.h>
#define OuO 1000000007

int main() {
    int T, sum = 0;
    scanf("%d", &T);
    while (T--) {
        int b, f = 0;
        scanf("%d", &b);
        switch (b) {
            case 6: {
                long long tmp;
                scanf("%lld", &tmp);
                for (int r = 1; tmp > 0; r *= 6, tmp /= 10)
                    f += (tmp % 10) * r;
                break;
            }
            case 8:
                scanf("%o", &f);
                break;
            case 10:
                scanf("%d", &f);
                break;
            case 16:
                scanf("%x", &f);
                break;
            default:
                break;
        }
        sum = (sum + f % OuO) % OuO;
    }
    printf("%d", sum);
}
