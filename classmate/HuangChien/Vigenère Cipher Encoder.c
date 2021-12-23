#include <stdio.h>

int main() {
    int length;
    scanf("%d\n", &length);
    char letter;
    unsigned char ch[10000] = {};
    int num[10000] = {};
    for (int i = 0; i < length; i++) {
        scanf("%c", &letter);
        num[i] = letter - 'a';
    }
    scanf("\n");
    int k = 0;
    int hc;
    for (int i = 0;; i++) {
        hc = getchar();
        if (hc == EOF)
            break;
        if ('A' <= hc && 'Z' >= hc) {
            hc += num[k % length];
            if (hc > 90) {
                hc = hc - 26;
            }
            k++;
        } else if ('a' <= hc && 'z' >= hc) {
            hc += num[k % length];
            if (hc > 122) {
                hc = hc - 26;
            }
            k++;
        }
        putchar(hc);
    }
    return 0;
}