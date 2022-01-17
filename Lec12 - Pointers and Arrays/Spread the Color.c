#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};  // Red, Green, Blue, Empty

void spread(char *, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();  // Ignore '\n'
    }
    scanf("%d %d", &row, &col);  // Starting position

    spread(&graph[0][0], row, col);

    // Print out the spreading result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}

void spread(char *graph, int row, int col) {
    char *rg[M];
    for (char *i = graph, k = 0; i < graph + M * N; i += N, k++)
        rg[k] = i;
    int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        char tc = rg[row][col];
        int ni = row, nj = col;
        while (ni < M && ni >= 0 && nj < N && nj >= 0 && (rg[ni][nj] == tc || rg[ni][nj] == 'X')) {
            rg[ni][nj] = tc;
            ni += d[i][0];
            nj += d[i][1];
        }
    }
}