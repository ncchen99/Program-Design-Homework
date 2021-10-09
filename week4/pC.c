#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int xx = 0;
    for (int i = 0; i < 12; i++) {
        int tmp;
        scanf("%1d", &tmp);
        if (i % 2)
            xx += tmp * 3;
        else
            xx += tmp;
    }
    printf("%d", (xx % 10 == 0 ? 0 : ((xx / 10) + 1) * 10 - xx));
}
