#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        float a;
        scanf("%f", &a);
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int b = 0;
            b |= (*(int *)&(*((char *)&a + i)));
            // for (int j = 7; j >= 0; j--)
            //     printf("%d", b >> j & 1);
            // printf("\n");
            sum += b;
        }
        if (sum & 1)
            printf("Back\n");
        else
            printf("Front\n");
    }
    return 0;
}
