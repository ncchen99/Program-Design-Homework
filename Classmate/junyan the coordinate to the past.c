#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define int __uint128_t
int addition(int sum);

signed main(void) {
    int oddSum = 0, evenSum = 0, counter = 0, tmp = 0;
    while (scanf("%1llx", &tmp) != EOF) {
        if (counter % 2 == 0)
            evenSum += tmp;
        else if (counter % 2 == 1)
            oddSum += tmp;
        counter++;
    }
    addition(oddSum);
    addition(evenSum);
    return 0;
}

int addition(int sum) {
    if (sum / 16 == 0) {
        printf("%x", sum);
        return 0;
    }

    int a[10001] = {}, oddSum = 0, evenSum = 0, sumTmp = sum, counter = 0;
    for (int i = 0;; i++) {
        a[i] = sumTmp % 16;
        sumTmp /= 16;
        counter++;
        if (sumTmp == 0) break;
    }
    for (int i = 0;; i++) {
        if (i % 2 == 0)
            oddSum += a[i];
        else if (i % 2 == 1)
            evenSum += a[i];
        if (i == counter - 1) break;
    }
    addition(oddSum);
    addition(evenSum);
}
