#include <math.h>
#include <stdio.h>
#define PI 3.14159265
typedef struct Point {
    double x;
    double y;
} point;

int main() {
    int n;
    point a[2000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &(a[i].x), &(a[i].y));
        printf("%.2lf %.2lf\n", atan2(a[i].y, a[i].x) * 180 / PI, sqrt(a[i].x * a[i].x + a[i].y * a[i].y));
    }
}