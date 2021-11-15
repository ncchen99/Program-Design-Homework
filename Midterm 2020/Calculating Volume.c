#include <math.h>
#include <stdio.h>
int main() {
    int m;
    scanf("%d", &m);
    double n;
    scanf("%lf", &n);
    if (m == 1)
        printf("%.2lf", pow(n, 3));
    if (m == 2) {
        double q, k;
        scanf("%lf%lf", &q, &k);
        printf("%.2lf", n * q * k);
    }
    if (m == 3) {
        double q;
        scanf("%lf", &q);
        printf("%.2lf", 3.14 * pow(n, 2) * q);
    }

    if (m == 4)
        printf("%.2lf", sqrt(2.0) / 12 * pow(n, 3));
}