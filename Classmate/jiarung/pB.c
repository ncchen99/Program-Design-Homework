#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    // 如果 n 不是 0
    int isFirstFactor = 1;
    int factor = 2;
    int time = 0;
    if (n == 1) {
        printf("1\n");
    }
    while (n != 1) {
        // 如果 factor 是 n 的因數
        if (n % factor == 0) {
            // 是第一個印出來的因數
            time = time + 1;
            n = n / factor;
        } else {
            if (time != 0) {
                if (isFirstFactor == 1) {
                    printf("%d^%d", factor, time);
                    isFirstFactor = 0;
                } else
                    printf("*%d^%d", factor, time);
            }
            factor = factor + 1;
            time = 0;
        }
        if (n == 1 && time != 0) {
            if (isFirstFactor == 1) {
                printf("%d^%d", factor, time);
                isFirstFactor = 0;
            } else
                printf("*%d^%d", factor, time);
        }
    }
    printf("\n");
}