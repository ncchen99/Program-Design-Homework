#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        __uint128_t a = 0;
        int si = 0;
        scanf("%d-%llx", &si, &a);
        __uint128_t mask = 0;
        // printf("si:%d", si);
        for (int j = si; j < si + 8; j++)
            mask |= ((unsigned long long)1 << j);
        a &= mask;
        for (int j = 63; j >= 0; j--) {
            if ((j + 1) % 8 == 0 && j != 63)
                printf(" ");
            printf("%d", ((a >> j) & 1));
        }
        printf("\n");
    }
}