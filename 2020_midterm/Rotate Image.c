#include <stdio.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int main() {
    int d, r, c, o[101][101] = {0}, a[101][101] = {0};
    scanf("%d%d%d", &d, &r, &c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &o[i][j]);
    for (int i = 0; i < d / 90; i++) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) a[j][r - i - 1] = o[i][j];
        swap(&r, &c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) o[i][j] = a[i][j];
    }
    for (int i = 0; i < r; i++, printf("\n"))
        for (int j = 0; j < c; j++) printf("%d ", a[i][j]);
}

