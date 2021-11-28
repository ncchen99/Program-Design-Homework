#include <stdio.h>

int main() {
    int origin, length, seat = 1;
    char name;
    int a[100][100];
    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < 100; i++) {
            a[i][j] = 999;
        }
    }

    scanf("%d", &origin);
    for (int i = 0; i < (origin + 1); i++) {
        scanf("%d ", &length);
        a[i][0] = length;
        for (int k = 1; k < (length + 1); k++) {
            scanf("%c", &name);
            if (name <= 'Z' && name >= 'A') {
                a[i][k] = (name + 32);
            } else
                a[i][k] = name;
        }
    }
    // printf("a[0][0]: %d\n", a[0][0]);
    for (int j = 1; j < (a[0][0] + 1); j++) {
        for (int i = 1; i < (origin + 1); i++) {
            if (a[i][0] == 999 || a[i][0] < j)
                continue;
            // printf("now j = %d\n", j);
            // for (int k = 0; k < origin + 1; k++) {
            //     printf("length of a[%d] = %d\n", k, a[k][0]);
            //     for (int ii = 0; ii < 16; ii++) {
            //         printf("%d\t", a[k][ii]);
            //     }
            //     printf("\n");
            // }
            // if (a[i][j] == 999)
            //     continue;
            if (j == a[i][0] && a[0][j] == a[i][j]) {
                if (a[0][0] > a[i][0])
                    seat += 1;
            } else {
                if (a[0][j] > a[i][j]) {
                    seat += 1;
                    for (int p = 0; p < 100; p++) {
                        a[i][p] = 999;
                    }
                } else if (a[0][j] < a[i][j]) {
                    for (int p = 0; p < 100; p++) {
                        a[i][p] = 999;
                    }
                }
            }
            // printf("\nafter process j = %d, seat = %d\n", j, seat);
            // for (int k = 0; k < origin + 1; k++) {
            //     printf("length of a[%d] = %d\n", k, a[k][0]);
            //     for (int ii = 0; ii < 16; ii++) {
            //         printf("%d\t", a[k][ii]);
            //     }
            //     printf("\n");
            // }
        }
    }
    printf("%d\n", seat);
    return 0;
}