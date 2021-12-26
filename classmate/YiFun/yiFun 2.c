#include <stdio.h>

int main() {
    long long int k, n;
    unsigned char ch;
    char b;
    scanf("%lld \n", &k);
    scanf("%c\n", &b);
    // scanf(" %lld\n", &k);

    while (k < 0)
        k = k + 26;
    k = k % 26;
    if (b == 'a') {
        while ((ch = getchar()) != '\n') {
            if (ch <= 90 && ch >= 65) {
                ch = ch + (k % 26);
                if (ch > 90)
                    ch = ch - 26;
                k += 1;
            }

            if (ch <= 122 && ch >= 97) {
                ch = ch + (k % 26);
                if (ch > 122)
                    ch = ch - 26;
                k += 1;
            }

            printf("%c", ch);
        }
    }

    if (b == 'd') {
        while ((ch = getchar()) != '\n') {
            if (ch <= 90 && ch >= 65) {
                if (k < 0)
                    k += 26;
                ch = ((ch - 'A' + (k % 26)) % 26) + 'A';
                k -= 1;
            }

            if (ch <= 122 && ch >= 97) {
                if (k < 0)
                    k += 26;
                ch = ((ch - 'a' + (k % 26)) % 26) + 'a';
                k -= 1;
            }
            printf("%c", ch);
        }
    }
    return 0;
}