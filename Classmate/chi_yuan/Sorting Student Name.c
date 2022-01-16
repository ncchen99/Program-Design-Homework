#include <stdio.h>
#include <string.h>
int main() {
    int N, check[1000] = {}, position;
    scanf("%d", &N);
    char a[1000][101], b[1000][101], copya[1000][101], copyb[1000][101];
    for (int i = 0; i < N; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < N; ++i) {
        strcpy(b[i], a[i]);  //b是原本的，a是拿來進行大小寫轉換及比較
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] >= 65 && a[i][j] <= 90) a[i][j] += 32;  //全部變小寫
        }
    }
    for (int i = 0; i < N; ++i) {
        check[i] = 0;
    }
    for (int i = 0; i < N; ++i) {
        char up[101];
        for (int k = 0; k < 101; ++k) {
            up[k] = 'z';
        }
        for (int j = 0; j < N; ++j) {
            if (strcmp(a[j], up) <= 0 && check[j] == 0) {
                strcpy(up, a[j]);
                strcpy(copya[i], a[j]);
                strcpy(copyb[i], b[j]);
                position = j;
            }
        }
        check[position] = 1;
    }
    for (int i = 0; i < N; ++i) {
        puts(copyb[i]);
    }
    return 0;
}