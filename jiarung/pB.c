#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    // 如果 n 不是 0
    int isFirstFactor = 1;
    int factor = 2;
    if (n == 1) {
        printf("1\n");
    }
    while (n != 1) {
        // 如果 factor 是 n 的因數
        if (n % factor == 0) {
            // 是第一個印出來的因數
            if (isFirstFactor) {
                printf("%d", factor);
                isFirstFactor = 0;
            } else {
                printf("*%d", factor);
            }
            n = n / factor;
        } else {
            factor++;
        }
    }
    printf("\n");
}