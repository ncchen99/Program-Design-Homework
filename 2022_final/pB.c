#include <stdio.h>
#include <stdlib.h>

int pull_radish(int *l, int *r, int *pos, int x);

int main() {
    int N, y, x;
    scanf("%d %d %d", &N, &y, &x);
    int *farm = malloc(N * sizeof(int));

    // initialize farm[N]
    for (int i = 0; i < N; i++) {
        farm[i] = 1;
    }

    int total = pull_radish(&farm[0], &farm[N - 1], &farm[y], x);
    printf("%d\n", total);
    for (int i = 0; i < N; i++) {
        printf("%d ", farm[i]);
    }

    return 0;
}

// l represents the first radish to the left 左邊第一個
// r represents the first radish to the right 右邊第一個
// pos represents Ariel's position
// x represents the interval
int pull_radish(int *l, int *r, int *pos, int x) {
    int ans = 0;
    int *posbk = pos;
    pos -= x;
    while (pos >= l) {
        *pos = 0;
        pos -= x;
        ans++;
    }
    posbk += x;
    while (posbk <= r) {
        *posbk = 0;
        posbk += x;
        ans++;
    }
    return ans;
}