#include <stdio.h>
int main() {
    int move[4][2] = {
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0}};  // 左 上 右 下
    int n, d, mat[50][50];
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int nowi = n / 2, nowj = n / 2;
    double c = 1;
    for (int i = 0; i < 2 * n - 1; i++, c += 0.5) {
        for (int j = 0; j < (int)c; j++) {
            printf("%d", mat[nowi][nowj]);
            nowi += move[d % 4][0];
            nowj += move[d % 4][1];
        }
        // printf("nowi = %d, nowj = %d\n", nowi, nowj); 
        d += 1;
    }
}