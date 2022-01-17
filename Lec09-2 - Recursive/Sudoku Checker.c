#include <stdio.h>
#define NUM 9

void check_sudoku(int grid_p[][NUM]);

int main(void) {
    int grid[NUM][NUM];  // sudoku puzzle
    for (int i = 0; i < NUM; ++i) {
        for (int j = 0; j < NUM; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int grid_p[][NUM]) {
    // c
    int ans[NUM][NUM] = {0};

    for (int j = 0; j < NUM; j++) {
        int r[NUM + 1] = {0};
        for (int i = 0; i < NUM; i++) {
            if (!r[grid_p[i][j]])
                r[grid_p[i][j]] = 1;
            else {
                ans[i][j] = 1;
                for (int k = 0; k < NUM; k++) {
                    if (grid_p[k][j] == grid_p[i][j]) {
                        ans[k][j] = 1;
                    }
                }
            }
        }
    }
    // c
    for (int i = 0; i < NUM; i++) {
        int r[NUM + 1] = {0};
        for (int j = 0; j < NUM; j++) {
            if (!r[grid_p[i][j]])
                r[grid_p[i][j]] = 1;
            else {
                ans[i][j] = 1;
                for (int k = 0; k < NUM; k++) {
                    if (grid_p[i][k] == grid_p[i][j]) {
                        ans[i][k] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int r[NUM + 1] = {0};
            for (int k = 0; k < 3; k++) {
                for (int w = 0; w < 3; w++) {
                    if (!r[grid_p[i + k][j + w]]) {
                        r[grid_p[i + k][j + w]] = 1;
                    } else {
                        ans[i + k][j + w] = 1;
                        for (int kk = 0; kk < 3; kk++) {
                            for (int ww = 0; ww < 3; ww++) {
                                if (grid_p[i + kk][j + ww] == grid_p[i + k][j + w]) {
                                    ans[i + kk][j + ww] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < NUM; i++)
        for (int j = 0; j < NUM; j++)
            if (ans[i][j])
                printf("(%d,%d)\n", i, j);
    printf("\n");
}
