#include <math.h>
#include <stdio.h>

struct stu {
    char n[1001];
    int nl;
    int id;
};

int cmp(char a[], char b[], int al, int bl) {
    for (int i = 0; i < (al < bl ? al : bl); i++) {
        if (a[i] == b[i])
            continue;
        else if (a[i] > b[i])
            return 0;
        else
            return 1;
    }
    return (al > bl ? 0 : 1);
}

int main() {
    int n, fid = 1;
    struct stu s[1001];
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        scanf("%d %s", &s[i].nl, s[i].n);
        for (int j = 0; j < s[i].nl; j++) {
            if ('A' <= s[i].n[j] && s[i].n[j] <= 'Z')
                s[i].n[j] = s[i].n[j] + ('a' - 'A');
        }
        s[i].id = i + 1;
    }

    for (int i = 0; i < n + 1; i++)
        for (int j = i + 1; j < n + 1; j++)
            if (!cmp(s[i].n, s[j].n, s[i].nl, s[j].nl)) {
                // printf("swap name:%s to name:%s", s[i].n, s[j].n);
                int tmpid = s[j].id;
                int tmpnl = s[j].nl;
                char tmpn[1001];
                for (int k = 0; k < tmpnl; k++) {
                    tmpn[k] = s[j].n[k];
                }
                s[j].id = s[i].id;
                s[j].nl = s[i].nl;
                for (int k = 0; k < s[i].nl; k++) {
                    s[j].n[k] = s[i].n[k];
                }
                s[i].id = tmpid;
                s[i].nl = tmpnl;
                for (int k = 0; k < tmpnl; k++) {
                    s[i].n[k] = tmpn[k];
                }
            }
    // for (int i = 0; i < n + 1; i++)
    //     printf("id:%d name:%s\n", s[i].id, s[i].n);

    for (int i = 0; i < n + 1; i++)
        if (s[i].id == 1)
            printf("%d\n", i + 1);
    return 0;
}
