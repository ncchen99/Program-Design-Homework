#include <stdio.h>
#include <stdlib.h>
int main() {
    int w, i, j, k;
    long long int sum = 0;
    __uint128_t a = 1, b = 1;  //a和b是做階層的
    scanf("%lld", &w);
    if (w >= 10) {
        w = w / 10;
        for (i = 1; i <= w / 2; i++) {
            k = w - 2 * i;  //k是直立的個數
            if (i >= k && k > 0) {
                for (j = i + k; j > i; j--) {
                    a = a * j;
                }
                for (j = 1; j <= k; j++) {
                    b = b * j;
                }
            } else if (k > i) {
                for (j = i + k; j > k; j--) {
                    a = a * j;
                }
                for (j = 1; j <= i; j++) {
                    b = b * j;
                }
            }
            sum = sum + a / b;
            a = b = 1;
        }
        printf("%lld", sum + 1);  //加上全部都是直立的
    } else
        printf("%lld", sum);
}