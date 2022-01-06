#include <stdio.h>
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
    int sum[1001] = {0}, c, number_max = 0, sum_max = 0;
    for (c = 0; s[c] != -1;) {
        if (s[c] < 60)
            s[c] = -1;
        c++;
    }
    for (int i = 0; i < c; i++) {
        int b = i;
        int sum = 0;
        while (*(s + i) != -1) {
            sum += *(s + i);
            i++;
        }
        if (sum > sum_max) {
            sum_max = sum;
            number_max = b;
        }
    }
    return s + number_max;
}