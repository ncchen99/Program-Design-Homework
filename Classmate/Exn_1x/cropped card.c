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
    int length = 0, maxlength = 0, sum = 0, max_sum = 0;
    int *finish = s;
    int *i = s;
    while (*i != -1) {
        if (*i >= 60) {
            length++;
            sum += *i;
        }
        if (*i < 60) {
            printf("length:%d, sum:%d", length, sum);
            if (length > maxlength) {
                maxlength = length;
                max_sum = sum;
                finish = i - 1;
            }
            if (length == maxlength) {
                if (max_sum <= sum) {
                    max_sum = sum;
                    finish = i - 1;
                }
            }

            length = 0;
            sum = 0;
        }
        i++;
    }
    if (length > maxlength) {
        maxlength = length;
        max_sum = sum;
        finish = i - 1;
    }
    if (length == maxlength) {
        if (max_sum <= sum) {
            max_sum = sum;
            finish = i - 1;
        }
    }

    *(finish + 1) = -1;
    s = finish - maxlength + 1;
    return s;
}