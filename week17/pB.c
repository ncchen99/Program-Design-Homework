#include <stdio.h>
#include <stdlib.h>

struct card {
    struct card* next;
    int v;
};

int main() {
    struct card top, cur, prev;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        cur.v = i + 1;
        if (!top) {
            top = cur;
        } else {
            prev->next = cur;
        }
        prev = cur;
    }
    for (int j = 0; j < m; j++) {
        if (!(j & 1)) {
            printf("%d", top->v);
            top = top->next;
        } else {
            struct card* toptmp = top;
            for (cur = top; cur->next != NULL; cur = cur->next) {
            }
            cur->next = toptmp;
            toptmp->next = NULL;
            top = top->next;
        }
    }
    // for (cur = top; cur != NULL; cur = cur->next)
    //     printf("value:%d", cur->v);
}