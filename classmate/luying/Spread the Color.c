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
    char *start = graph + row * 8 + col;
    for (int i = 1; start - i >= graph + row * 8; i++) {  //左邊
        if (*(start - i) == 'X')
            *(start - i) = *start;
        else if (*(start - i) != 'X' && *(start - i) != *(start))
            break;
    }
    for (int i = 1; start + i <= graph + row * 8 + 7; i++) {  //右邊
        if (*(start + i) == 'X')
            *(start + i) = *start;
        else if (*(start + i) != 'X' && *(start + i) != *(start))
            break;
    }
    // printf("strat:%c end:%c\n bool:%d", *start, *(graph + col), start - 8 * 1 >= graph + col);
    for (int i = 1; (start - (8 * i)) >= graph + col; i++) {  //上面
        if (*(start - 8 * i) == 'X')
            *(start - 8 * i) = *start;
        else if (*(start - 8 * i) != 'X' && *(start - 8 * i) != *(start))
            break;
    }
    for (int i = 1; start + 8 * i <= graph + 32 + col; i++) {  //下面
        if (*(start + 8 * i) == 'X')
            *(start + 8 * i) = *start;
        else if (*(start + 8 * i) != 'X' && *(start + 8 * i) != *(start))
            break;
    }
    return;
}
