#include <math.h>
#include <stdio.h>
#include <string.h>
int main() {
    unsigned long long number;
    int digit[10000], bigdigit[10000] = {0}, smalldigit[10000] = {0}, i;
    while (scanf("%lld", &number) != EOF) {
        __uint128_t real_number = number;
        for (i = 0; number > 0; i++) {
            digit[i] = number % 10;  //把各個位數存起來
            number /= 10;
            bigdigit[i] = digit[i];
            smalldigit[i] = digit[i];
        }
        int j = i - 1, k;
        __uint128_t big = 0, small = 0, an_big, an_small;
        for (i = j; i >= 0; i--) {
            if (digit[i] % 2 == 0) {  //由左而右霸偶數的加一，然後比他小的位數全部變成1
                bigdigit[i] = digit[i] + 1;
                for (k = i - 1; k >= 0; k--)
                    bigdigit[k] = 1;
                break;
            }
        }
        for (i = 0; i <= j; i++) {  //把big算出來，這個是比原數字大的完全奇數
            big += bigdigit[i] * pow(10, i);
        }
        an_big = big - real_number;
        printf("%lld\n", big);
        for (i = j; i >= 0; i--) {
            if (digit[i] % 2 == 0 && digit[i] != 0) {  //由左而右如果遇到偶數就把他減一，然後把比他小的位數都變成9
                smalldigit[i] = digit[i] - 1;
                for (k = i - 1; k >= 0; k--)
                    smalldigit[k] = 9;
                break;
            }
            if (digit[i] == 0 && digit[i + 1] != 1) {  //如果第一個遇到的偶數是0，就要把他變成9然後前面那個位數-2
                smalldigit[i] = 9;
                for (k = i - 1; k >= 0; k--)
                    smalldigit[k] = 9;
                smalldigit[i + 1] = digit[i + 1] - 2;
                break;
            }
            if (digit[i] == 0 && digit[i + 1] == 1) {  //如果第一個偶數前面位數的數都是1，就要借位
                smalldigit[i] = 9;
                for (k = i - 1; k >= 0; k--) {
                    smalldigit[k] = 9;
                }
                for (k = i + 1; digit[k] == 1 && k < j; k++) {
                    smalldigit[k] = 9;
                }
                if (k != j) {
                    smalldigit[k] = digit[k] - 2;
                } else
                    smalldigit[k] = 0;
                break;
            }
        }
        for (i = 0; i <= j; i++) {  //算出small，這個是比原數字小的完全奇數
            small += smalldigit[i] * pow(10, i);
        }
        an_small = real_number - small;
        printf("%lld\n", small);
        if (an_big > an_small)
            printf("%lld\n", (long long)an_small);
        else
            printf("%lld\n", (long long)an_big);
    }
    return 0;
}