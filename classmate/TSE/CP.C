//
//  main.c
//  W12H2
//
//  Created by jamestsai on 2021/12/17.
//

#include <stdio.h>

void rotate_r(int m, int n, int rotate_num);
void rotate_l(int m, int n, int rotate_num);
void vertical_flip(int m, int n);
void horizontal_flip(int m, int n);
void crop(int m, int n, int left, int right, int high, int low);
void output(int m, int n);
int picture[100][100];

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
            rotate_num %= 4;
            if (rotate_num >= 0) {
                if (ch2 == 'r') {
                    rotate_r(m, n, rotate_num);
                }
                if (ch2 == 'l') {
                    rotate_l(m, n, rotate_num);
                }
            } else {
                if (ch2 == 'r') {
                    rotate_num *= -1;
                    rotate_l(m, n, rotate_num);
                }
                if (ch2 == 'l') {
                    rotate_num *= -1;
                    rotate_r(m, n, rotate_num);
                }
            }
            if (rotate_num == 1 || rotate_num == 3 || rotate_num == -1 || rotate_num == -3) {
                change = m;
                m = n;
                n = change;
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

void rotate_r(int m, int n, int rotate_num) {
    int initial[100][100] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            initial[i][j] = picture[i][j];
        }
    }
    if (rotate_num == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                picture[i][j] = initial[m - 1 - j][i];
            }
        }
    }
    if (rotate_num == 2) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                picture[i][j] = initial[m - 1 - i][n - 1 - j];
            }
        }
    }
    if (rotate_num == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                picture[i][j] = initial[j][1 - i];
            }
        }
    }
}

void rotate_l(int m, int n, int rotate_num) {
    int initial[100][100] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            initial[i][j] = picture[i][j];
        }
    }
    if (rotate_num == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                picture[i][j] = initial[m - 1 - j][i];
            }
        }
    }
    if (rotate_num == 2) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                picture[i][j] = initial[m - 1 - i][n - 1 - j];
            }
        }
    }
    if (rotate_num == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                picture[i][j] = initial[j][1 - i];
            }
        }
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
    int initial[100][100] = {0};
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