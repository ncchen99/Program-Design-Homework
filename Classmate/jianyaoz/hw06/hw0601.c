#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "mirror.h"

int main() {
    int i, n;
    time_t t;
    /* Intializes random number generator */
    srand((unsigned)time(&t));

    double x[2], y[2];
    for (i = 0; i < 2; i++) {
        x[i] = rand() % 50;
        y[i] = rand() % 50;
    }
    // scanf("%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1]);
    printf("x1:%lf y1:%lf, x2:%lf y2:%lf\n", x[0], y[0], x[1], y[1]);
    set_line(x[0], y[0], x[1], y[1]);
    double a = rand() % 50;
    double b = rand() % 50;
    double c = 0, d = 0;
    printf("a:%lf, b:%lf\n", a, b);
    int32_t r = get_mirror(a, b, &c, &d);
    if (!r)
        printf("c:%lf d:%lf\n", c, d);
    else
        printf("Invalid!\n");
    return 0;
}