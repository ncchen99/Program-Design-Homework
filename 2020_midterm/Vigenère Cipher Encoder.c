#include <stdio.h>

int main(void) {
    int kl, n = 0;
    int k[1001] = {};
    scanf("%d", &kl);
    getchar();
    for (int i = 0; i < kl + 1; i++)
        k[i] = (getchar() - 'a');
    for (char c; (c = getchar()) != '\n';) {
        if ('A' <= c && c <= 'Z')
            printf("%c", (c + k[(n++ % kl)] - 'A') % 26 + 'A');
        else if ('a' <= c && c <= 'z')
            printf("%c", (c + k[(n++ % kl)] - 'a') % 26 + 'a');
        else
            printf("%c", c);
    }
}
