#include <stdio.h>
int n, bn;
int bc[110][110] = {0};
int tmp[110] = {0};
int dfs(int now) {
    tmp[now] = 1;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (bc[now][i] == 1)
            c++;
    }
    // printf("n: %d c:%d", now, c);
    if (c == 1) return 0;
    for (int i = 1; i <= n; i++) {
        if (bc[now][i] == 1 && i != now) {
            // printf("now n:%d move to i:%d\n", now, i);
            dfs(i);
        }
    }
}
int main() {
    scanf("%d", &n);

    while (scanf("%d", &bn)) {
        if (bn == 0)
            break;
        int br;
        char c;
        while (scanf("%d%c", &br, &c)) {
            bc[bn][br] = 1;
            if (c == '\n')
                break;
        }
    }
    for (int i = 1; i <= n; i++) {
        bc[i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= n; i++) {
            tmp[i] = 0;
        }
        printf("%d -> ", i);
        dfs(i);
        for (int i = 1; i <= n; i++) {
            if (tmp[i] == 1)
                printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
