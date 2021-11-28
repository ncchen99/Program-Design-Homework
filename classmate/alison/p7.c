#include <stdio.h>

int main() {
    float n;
    scanf("%f", &n);
    float a = 0, b = n, c;
    while (b - a > 0.00001) {
        c = (a + b) / 2;
        if (c * c >= n)
            b = c;
        else
            a = c;
    }
    printf("%.4f\n", c);
}