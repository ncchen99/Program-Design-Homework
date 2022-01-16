#include <stdio.h>
#include <stdlib.h>

typedef struct Bank {
    char name[101];
    int a;  //amount
} bank;

int cmp(bank* a, bank* b) {
    return (*a).a < (*b).a;
}

int main() {
    int n, money_need;
    bank b[105];
    scanf("%d%d", &n, &money_need);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", b[i].name, &b[i].a);
    }

    // 使用 qsort 排序
    qsort(b, n, sizeof(b[0]), cmp);

    // for (int i = 0; i < n; i++) {
    //     printf("c[%d] s=%d, e =%d\n", i, c[i].s, c[i].e);
    // }

    int sum = 0,
        i, last_money_amount;
    for (i = 0; i < n; i++) {
        if (sum + b[i].a >= money_need) {
            last_money_amount = money_need - sum;
            break;
        } else
            sum += b[i].a;
    }
    if (i == n)
        printf("not possible!\n");
    else {
        for (int j = 0; j < i; j++) {
            printf("%s %d\n", b[j].name, b[j].a);
        }
        printf("%s %d\n", b[i].name, last_money_amount);
    }
}