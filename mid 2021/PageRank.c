#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int mat[110][110] = {0.0};
    long double value[110];
    long double amount[110] = {};
    for (int i = 0; i < n; i++) {
        int num, c = 0;
        while (scanf("%d", &num)) {
            if (num == -1) {
                amount[i] = c;
                break;
            }
            mat[i][num] = 1;
            c++;
        }
        value[i] = 1.0 / (long double)n;
    }
    long double prev = 0.0;
    for (int i = 0; i < 1000; i++) {
        long double valuetmp[105] = {};
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (amount[j] < 0.000000001)
                    continue;
                if (mat[j][k]) {
                    valuetmp[k] += value[j] / amount[j];
                    valuetmp[j] -= value[j] / amount[j];
                }
            }
        }
        long double diff = 0;
        for (int j = 0; j < n; j++) {
            value[j] += valuetmp[j];
            diff += value[j];
        }
        diff /= (long double)n;
        printf("prev:%llf diff:%llf\n", prev, diff);
        printf("abs(prev - diff) = %llf", abs(prev - diff));
        if (abs(prev - diff) < 0.00000000009) {
            break;
        }
        prev = diff;
    }
    for (int i = 0; i < n; i++) {
        printf("%.2llf%% ", value[i] * 100);
    }
    printf("\n");
    return 0;
}
