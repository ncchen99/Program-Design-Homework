#include <stdio.h>
#define g 9.8f

int main() {
    int h;
    double x = 0, t = 0;
    scanf("%d", &h);
    while (x >= 0) {
        x = (0.5 * g * t * t);
        if (x >= h)
            break;
        printf("%.1f\n", h - x);
        t++;
    }
    return 0;
}