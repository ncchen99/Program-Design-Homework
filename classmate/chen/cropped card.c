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
    int result1[1010] = {0}, *result2 = malloc(sizeof(int) * 1010);
    int digit = 0, ini_digit = 0, sum = 0, sum_max = 0;

    for (int k = 0;;) {
        while (s[k] >= 60) {
            result1[digit++] = s[k++];
            // printf("kk:%d\n", result1[digit - 1]);。
            // for (int i = 0; i < digit; i++)
            // printf("%d ", result1[i]);
        }
        result1[digit++] = -1;

        for (int l = 0; l < digit - 1; l++) {
            sum += result1[l];
        }
        // printf("sum:%d\n", sum);
        if (sum >= sum_max) {
            sum_max = sum;
            for (int l = 0; l < digit; l++) {
                result2[l] = result1[l];
            }
        }
        digit = 0, sum = 0;
        if (s[k] == -1)
            break;
        else
            k++;
    }
    return result2;
}