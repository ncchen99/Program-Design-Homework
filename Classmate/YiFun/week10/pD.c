#include <stdio.h>

void decode(int num) {
    int sumOfEven = 0, sumOfOdd = 0;
    if (num < 16) {
        printf("%x", num);
        return;
    }
    for (int i = 1; num != 0; i++, num /= 16)
        if (i & 1)
            sumOfOdd += num % 16;
        else
            sumOfEven += num % 16;
    decode(sumOfOdd);
    decode(sumOfEven);
}

int main() {
    int num, i = 1, sumOfEven = 0, sumOfOdd = 0;
    while (scanf("%1x", &num) != EOF)
        if (i++ & 1)
            sumOfEven += num;
        else
            sumOfOdd += num;
    decode(sumOfOdd);
    decode(sumOfEven);
}
