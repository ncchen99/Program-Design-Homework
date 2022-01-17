#include <stdint.h>
#include <stdio.h>

int bingo(uint16_t num[]);

int main() {
    uint16_t num[8];
    for (int i = 0; i < 8; ++i) {
        scanf("%hu", &num[i]);
    }

    printf("%d\n", bingo(num));
}

int bingo(uint16_t num[]) {
    //     for (int i = 0; i < 8; i++, printf("\n"))
    //         for (int j = 0; j < 8; j++)
    //             printf("%d", (num[i] >> j) & 1);
    int ans = 0, i = 0, j = 0;
    for (i = 0; i < 8; i++) {
        ans += (num[i] == 255 ? 1 : 0);
    }
    // printf("恆的ans:%d\n", ans);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            if (!((num[j] >> i) & 1)) break;
        ans += j / 8;
    }
    // printf("值得ans:%d\n", ans);
    for (i = 0; i < 8; i++) {
        if (!((num[i] >> i) & 1)) break;
    }
    ans += i / 8;
    // printf("右斜ans:%d\n", ans);
    for (i = 7, j = 0; i >= 0 && j < 8; i--, j++) {
        if (!((num[j] >> i) & 1)) break;
    }
    ans += j / 8;
    // printf("左斜ans:%d, i:%d\n", ans, i);
    return ans;
}