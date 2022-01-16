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
    int num_tem[8][8] = {0};
    int count = 0;
    // store into 2d array:num_tem
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            // printf("%d", (num[i] >> j) & 1);
            num_tem[i][j] = (num[i] >> j) & 1;
    }
    /* horizontal */
    for (int i = 0; i < 8; i++)
        if (num[i] == 255)
            count++;

    /*vertical*/
    for (int i = 0, isOk = 1; i < 8; i++, isOk = 1) {
        for (int j = 0; j < 8 && isOk; j++) {
            if (num_tem[j][i] != 1)
                isOk = 0;
        }
        if (isOk)
            count++;
    }

    /* slanting 右斜*/

    int isOk = 1;
    for (int i = 0; i < 8 && isOk; i++) {
        if (num_tem[i][i] != 1)
            isOk = 0;
    }
    if (isOk)
        count++;

    /* slanting 左斜*/

    isOk = 1;
    for (int i = 0; i < 8 && isOk; i++) {
        if (num_tem[i][8 - i - 1] != 1)
            isOk = 0;
    }
    if (isOk)
        count++;

    return count;
}