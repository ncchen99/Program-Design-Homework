#include <stdio.h>
#include <string.h>
#define swap(x, y)   \
    {                \
        int tmp = x; \
        x = y;       \
        y = tmp;     \
    }

char eat_trash() {
    char t;
    while ((t = getchar()) == '\n' || t == ' ') {
    }
    return t;
}
int main() {
    int n, m, ot;
    scanf("%d%d", &n, &m);
    int mat[105][105] = {};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
    scanf("%d", &ot);
    for (int i = 0; i < ot; i++) {
        char i = eat_trash();
        int tmp[105][105] = {};
        if (i == 'r') {
            char d = eat_trash();
            int t;
            scanf("%d", &t);
            if (d == 'r') {
                for (int j = 0; j < t; j++) {
                    for (int k = 0; k < n; k++)
                        for (int w = 0; w < m; w++)
                            tmp[w][n - k - 1] = mat[k][w];
                    memcpy(&mat, &tmp, sizeof(tmp));
                    swap(n, m);
                }
            }
            if (d == 'l') {
                for (int j = 0; j < t; j++) {
                    for (int k = 0; k < n; k++)
                        for (int w = 0; w < m; w++)
                            tmp[m - w - 1][k] = mat[k][w];
                    memcpy(&mat, &tmp, sizeof(tmp));
                    swap(n, m);
                }
            }
        }
        if (i == 'v') {
            for (int k = 0; k < n; k++)
                for (int w = 0; w < m; w++)
                    tmp[n - k - 1][w] = mat[k][w];
            memcpy(&mat, &tmp, sizeof(tmp));
        }
        if (i == 'h') {
            for (int k = 0; k < n; k++)
                for (int w = 0; w < m; w++)
                    tmp[k][m - w - 1] = mat[k][w];
            memcpy(&mat, &tmp, sizeof(tmp));
        }
        if (i == 'c') {
            int xs, xe, ys, ye;
            scanf("%d%d%d%d", &xs, &xe, &ys, &ye);
            for (int k = 0; k < ye - ys + 1; k++)
                for (int w = 0; w < xe - xs + 1; w++)
                    tmp[k][w] = mat[ys - 1 + k][xs - 1 + w];
            memcpy(&mat, &tmp, sizeof(tmp));
            n = ye - ys + 1;
            m = xe - xs + 1;
        }
        if (i == 'p') {
            for (int k = 0; k < n; k++, printf("\n"))
                for (int w = 0; w < m; w++)
                    printf("%d ", mat[k][w]);
            printf("\n");
        }
    }
}
