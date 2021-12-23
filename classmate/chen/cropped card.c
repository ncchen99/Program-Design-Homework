#include <stdio.h>
#include <stdlib.h>
int *report_card(int *s);

int main() {
    int score[1001];
    int *show;
    int count = 0;

    do {
        scanf("%d", &score[count++]);
    } while (score[count - 1] != -1);

    show = report_card(score);

    count = 0;
    while (*(show + count) != -1) {
        printf("%d ", *(show + count));
        count++;
    }
}
int *report_card(int *s) {
    int result1[1001] = {0}, result2[1001] = {0};
    int digit = 0, ini_digit = 0, sum = 0, sum_max = 0;

    for (int k = 0; *(s + k) != -1; k++) {
        while (*(s + k) != -1) {
            if (*(s + k) >= 60) {
                result1[digit++] = *(s + k);

                if (*(s + k + 1) < 60) break;
            }
            k++;
        }
        result1[digit++] = -1;

        for (int l = 0; l < digit; l++) {
            sum += result1[l];
        }
        if (sum >= sum_max && digit > ini_digit) {
            sum_max = sum;
            ini_digit = digit;

            for (int l = 0; l < digit; l++) {
                result2[l] = result1[l];
            }
        }
        for (int i = 0; i < digit; i++) result1[i] = 0;
        digit = 0, sum = 0;
    }
    int *p = result2;

    return p;
}