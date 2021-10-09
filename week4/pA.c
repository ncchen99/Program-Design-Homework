#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    float x;
    scanf("%f", &x);
    printf("%.1f", 7 * pow(x, 4) - 8 * pow(x, 3) - pow(x, 2) + 6 * x - 22);
}
