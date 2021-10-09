#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%1d%1d%1d%1d", &a, &b, &c, &d);
    // 用 %1d 殼以一次讀入一個位數
    printf("%d%d%d%d", d, c, b, a);
}