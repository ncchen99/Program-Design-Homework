#include <stdio.h>

int main() {
    int num, i, j, b, length = 0, row = 0, line = 0;
    int a[500], A[500], G[500][500];
    scanf("%d", &num);
    for (i = 0; i < 500; i++) {
        for (j = 0; j < 500; j++) {
            G[i][j] = (-1);
        }
    }
    for (i = 0; i < 500; i++) {
        A[i] = -1;
    }
    for (i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < num; i++) {
        line = 0;
        b = i;
        if (A[i] != (-1)) {
            continue;
        }
        length++;
        for (;;) {
            G[row][line] = b;
            A[b] = i;
            b = a[b];
            line++;
            if (b == i) {
                G[row][line] = b;
                row++;
                break;
            }
        }
    }
    if (length == 1) {
        printf("%d ring\n", length);
    } else {
        printf("%d rings\n", length);
    }
    for (i = 0, j = 0;; j++) {
        if (G[i][0] == (-1)) {
            break;
        }
        printf("%d", G[i][j]);
        if (G[i][j + 1] == (-1)) {
            printf("\n");
            i++;
            j = (-1);
            continue;
        }
        printf(" -> ");
    }

    return 0;
}