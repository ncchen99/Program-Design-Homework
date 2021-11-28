#include <math.h>
#include <stdio.h>

int main() {
    int n, i = 1;
    int factor = 1;
    scanf("%d", &n);

    if (n == 1)  // input number = 1
    {
        printf("1^1");
        return 0;
    }
    // 5/0 餘數 0
    for (factor = 2; pow(factor, i) <= n; factor++) {
        if (n != 1 && n > 0 && n / (float)factor < eps) {
            if (n / pow(factor, i) == 0) {
                i = i + 1;
                if (n / pow(factor, i) != 0) {
                    i = i - 1;
                    printf("%d^%d", factor, i);
                }
            }
        }
    }
}