#include <stdio.h>
int tree[40000] = {};
#define left(i) (i * 2)
#define right(i) (i * 2 + 1)
#define ld             \
    if (tree[left(n)]) \
        dfs(h, left(n));
#define rd              \
    if (tree[right(n)]) \
        dfs(h, right(n));
int dfs(int h, int n) {
    if (h == 0) {
        printf("%d ", tree[n]);
        ld;
        rd;
    } else if (h == 1) {
        ld;
        printf("%d ", tree[n]);
        rd;
    } else {
        ld;
        rd;
        printf("%d ", tree[n]);
    }
}
int main() {
    int h, n;
    scanf("%d%d", &h, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &tree[i]);
    dfs(h, 1);
}