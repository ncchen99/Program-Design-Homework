#include <stdio.h>
int main() {
    int i, minNum = 1e9, maxNum = -1e9;
    int num;
    while (scanf("%d", &num) != EOF) {
        if (num > maxNum)
            maxNum = num;
        if (num < minNum)
            minNum = num;
    }
    printf("%d %d", maxNum, minNum);
    return 0;
}