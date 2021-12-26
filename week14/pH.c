#include <stdio.h>
#include <string.h>
int d, hp, at = 0, np = 0;
char lc[3][100] = {"PATA PATA PATA PON", "PON PON PATA PON", "CHAKA CHAKA PATA PON"};
int op(char *c, int sp, int ep) {
    char tmp[1000];
    strncpy(tmp, &c[sp], ep - sp);
    tmp[ep - sp] = '\0';
    for (int i = 0; i < 3; i++) {
        if (!strcmp(tmp, lc[i])) {
            if (i == 0) {
                // moveforward
                // printf("衝了!\n");
                d--;
                if (d <= 0)
                    return -1;
            }
            if (i == 1) {
                // attack
                // printf("打了!%s at:%d\n", (d <= 3 ? "有效" : "無效"), at);
                if (d <= 3)
                    hp--;
                if (hp <= 0)
                    return 1;
            }
            if (i == 2) {
                // back&defence
                // printf("退了!\n");
                d++;
            }
            at++;
            if (at % 10 == 0 && at > 0 && i != 2)
                return -1;
            break;
        }
    }
    return 0;   // 沒怎樣
    return 1;   // 營惹
    return -1;  // 鼠調
}
int main() {
    scanf("%d%d\n", &d, &hp);
    char c[100000], *dp = c, *cp = c;
    fgets(c, 100000, stdin);
    c[strlen(c) - 1] = '\0';
    while (1) {
        dp = strchr(&(c[np]), '.');
        cp = strchr(&(c[np]), ',');
        dp = (dp != NULL ? dp : c + strlen(c));
        cp = (cp != NULL ? cp : c + strlen(c));
        int r = op(c, np, (dp < cp ? dp - c : cp - c));
        if (r == 1)
            printf("YES %d\n", at + 1);
        if (r == -1)
            printf("NO %d\n", hp);
        if (r)
            return 0;
        np = (dp < cp ? dp - c : cp - c) + 1;
        if (np >= strlen(c)) {
            printf("NO %d\n", hp);
            break;
        }
    }
}
