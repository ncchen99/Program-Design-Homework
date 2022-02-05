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
#include <stdlib.h>
int *report_card(int *s) {
    static short a[1120][1120] = {0};
    short count[1120] = {0};
    int ans = 0;
    for (int i = 0; i < 1120; i++) {
        for (int j = 0; j < 1120; j++) {
            if (*s != -1) {
                if (*s >= 60) {
                    a[i][j] = *s;
                    count[i]++;
                    s++;
                } else {
                    s++;
                    break;
                }
            } else {  // *s == -1;
                for (int k = 0; k < 1120; k++) {
                    if (count[k] > count[ans]) {
                        ans = k;
                    } else if (count[k] == count[ans] && count[k] > 0) {
                        int sum1 = 0, sum2 = 0;
                        for (int l = 0; l < count[k]; l++) {
                            sum1 += a[ans][l];
                            sum2 += a[k][l];
                        }

                        if (sum2 > sum1) ans = k;
                    }
                }
                a[ans][count[ans]] = -1;
                break;
            }
        }
    }
    int *res = malloc((count[ans]+1) * sizeof(int));
    for (int w = 0; w < count[ans] + 1; w++)
        res[w] = a[ans][w];
    return res;
}