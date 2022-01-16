#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int all = a + b + c;
    printf("%d %d\n", all / 7, all % 7);
}
