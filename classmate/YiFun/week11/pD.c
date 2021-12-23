#include <stdio.h>
#include <string.h>
int main() {
    int a[10] = {0};
    for (int i = 0; i < 8; i++) {
        scanf("%d", &a[i]);
        if (i < 7) a[i] *= 1000;
    }
    for (; a[7]--;) {
        char cate[5];
        int kkbox, spotify;
        scanf("%s %d/%d\n", cate, &kkbox, &spotify);
        if (!strcmp(cate, "G")) {
            a[3] -= 500;
            a[8] += 20;
        }
        if (!strcmp(cate, "B")) {
            a[0] -= 500;
            a[8] += 20;
        }
        if (!strcmp(cate, "T")) {
            a[2] -= 500;
            a[8] += 30;
        }
        if (!strcmp(cate, "W")) {
            a[1] -= 500;
            a[8] += 15;
        }
        if (!strcmp(cate, "GT")) {
            a[2] -= 250;
            a[3] -= 250;
            a[8] += 45;
        }
        if (!strcmp(cate, "WT")) {
            a[2] -= 350;
            a[1] -= 150;
            a[8] += 40;
        }
        if (!strcmp(cate, "BM")) {
            a[0] -= 200;
            a[4] -= 300;
            a[8] += 35;
        }
        if (!strcmp(cate, "TM")) {
            a[2] -= 200;
            a[4] -= 300;
            a[8] += 45;
        }
        if (!strcmp(cate, "WM")) {
            a[1] -= 200;
            a[4] -= 300;
            a[8] += 30;
        }
        kkbox -= 1;
        spotify -= 1;
        if (kkbox == 1)
            a[5] -= 3;
        if (kkbox == 2)
            a[5] -= 5;
        if (kkbox == 3)
            a[5] -= 7;
        if (kkbox == 4)
            a[5] -= 10;
        if (spotify == 1)
            a[6] -= 30;
        if (spotify == 2)
            a[6] -= 50;
        if (spotify == 3)
            a[6] -= 70;
        if (spotify == 4)
            a[6] -= 100;
    }
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d\n", a[8]);
    return 0;
}
