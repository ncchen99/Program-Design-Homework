//
//  main.c
//  W12H2
//
//  Created by jamestsai on 2021/12/17.
//

#include <stdio.h>

void rotate_r(int *m, int *n, int rotate_num);
void rotate_l(int *m, int *n, int rotate_num);
void vertical_flip(int m, int n);
void horizontal_flip(int m, int n);
void crop(int m, int n, int left, int right, int high, int low);
void output(int m, int n);
int picture[200][200];

#define swap(x, y)   \
    {                \
        int tmp = x; \
        x = y;       \
        y = tmp;     \
    }

int main() {
    int m, n, change, rotate_num, operation_num;
    int left, right, high, low;
    char ab, ch1, ch2;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &picture[i][j]);
        }
    }
    scanf("%d", &operation_num);
    for (int i = 0; i < operation_num; i++) {
        ab = getchar();
        ch1 = getchar();
        if (ch1 == 'r') {
            ab = getchar();
            ch2 = getchar();
            scanf("%d", &rotate_num);

            if (ch2 == 'r') {
                rotate_r(&m, &n, rotate_num);
            }
            if (ch2 == 'l') {
                rotate_l(&m, &n, rotate_num);
            }
        }
        if (ch1 == 'v') {
            vertical_flip(m, n);
        }
        if (ch1 == 'h') {
            horizontal_flip(m, n);
        }
        if (ch1 == 'c') {
            scanf("%d%d%d%d", &left, &right, &high, &low);
            left--;
            high--;
            right--;
            low--;
            crop(m, n, left, right, high, low);
            m = low - high + 1;
            n = right - left + 1;
        }
        if (ch1 == 'p') {
            output(m, n);
            printf("\n");
        }
    }
}

void rotate_r(int *m, int *n, int rotate_num) {
    int initial[200][200] = {0};
    for (int l = 0; l < rotate_num; l++) {
        for (int i = 0; i < *m; i++) {
            for (int j = 0; j < *n; j++) {
                initial[i][j] = picture[i][j];
            }
        }
        for (int k = 0; k < *m; k++)
            for (int w = 0; w < *n; w++)
                picture[k][w] = initial[*m - 1 - w][k];
        swap(*n, *m);
    }
}

void rotate_l(int *m, int *n, int rotate_num) {
    int initial[200][200] = {0};
    for (int l = 0; l < rotate_num; l++) {
        for (int i = 0; i < *m; i++) {
            for (int j = 0; j < *n; j++) {
                initial[i][j] = picture[i][j];
            }
        }
        for (int k = 0; k < *m; k++)
            for (int w = 0; w < *n; w++)
                picture[k][w] = initial[w][*n - 1 - k];
        swap(*n, *m);
    }
}

void vertical_flip(int m, int n) {
    int initial[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            initial[i][j] = picture[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            picture[i][j] = initial[m - i - 1][j];
        }
    }
}

void horizontal_flip(int m, int n) {
    int initial[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            initial[i][j] = picture[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            picture[i][j] = initial[i][n - j - 1];
        }
    }
}

void crop(int m, int n, int left, int right, int high, int low) {
    int initial[200][200] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            initial[i][j] = picture[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            picture[i][j] = 0;
        }
    }
    for (int i = 0, highchange = high; i < low - high + 1; i++, highchange++) {
        for (int j = 0, leftchange = left; j < right - left + 1; j++, leftchange++) {
            picture[i][j] = initial[highchange][leftchange];
        }
    }
}

void output(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", picture[i][j]);
        }
        printf("\n");
    }
}