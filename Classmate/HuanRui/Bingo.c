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
    int bingo[8][8];
    for (int i = 0; i < 8; i++)
        for (int k = 7; k >= 0; --k)
            bingo[i][8 - k - 1] = (num[i] >> k) & 1;
}
