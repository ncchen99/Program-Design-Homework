#include "mirror.h"

#include <stdint.h>
#include <stdio.h>

double px[2] = {9e15, 9e15}, py[2] = {9e15, 9e15}, ca, cb = -1, cc;
// Use (x1,y1) and (x2,y2) to determine a line.
// If the input is not a valid line , use previous valid one.
void set_line(double x1, double y1, double x2, double y2) {
    if (x1 == x2 && y1 == y2) {
        x1 = px[0];
        x2 = px[1];
        y1 = py[0];
        y2 = py[1];
    } else {
        px[0] = x1;
        px[1] = x2;
        py[0] = y1;
        py[1] = y2;
    }
    ca = y1 - y2;
    cb = x2 - x1;
    cc = x1 * y2 - y1 * x2;
}
// Q(c,d) is the mirror of P(a,b) according to the predetermined line.
// If there is no valid line , return -1; otherwise , return 0.
int32_t get_mirror(double a, double b, double *c, double *d) {
    if (px[0] == px[1] && py[0] == py[1])
        return -1;
    if (px[0] == px[1]) {
        *c = 2 * px[0] - a;
        *d = b;
    } else if (py[0] == py[1]) {
        *c = a;
        *d = 2 * py[0] - b;
    } else {
        *c = a - 2 * ca * ((ca * a + cb * b + cc) / (ca * ca + cb * cb));
        *d = b - 2 * cb * ((ca * a + cb * b + cc) / (ca * ca + cb * cb));
    }
    return 0;
}
