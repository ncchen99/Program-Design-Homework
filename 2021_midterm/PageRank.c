#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int mat[103][103] = {0};
    double value[103];
    int amount[103] = {0};
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
        value[i] = 1.0 / (double)n;
    }
    for (int i = 0; i < 1000; i++) {
        double valuetmp[105] = {0};
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (mat[j][k]) {
                    valuetmp[k] += value[j] / amount[j];
                }
            }
        }
        for (int j = 0; j < n; j++) {
            value[j] = valuetmp[j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%.2llf%% ", value[i] * 100);
    }
    printf("\n");
    return 0;
}