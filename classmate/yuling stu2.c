#include <stdio.h>
int main() {
    int i = 0;
    int number;
    char name1[101];
    char name2[101];
    int j, k, n;

    int length1, length2;
    scanf("%d", &n);
    scanf("%d ", &length1);
    for (i = 1; i <= length1; i++) {  //length1是轉學生名字的長度
        scanf("%c", &name1[i]);
        if (97 <= name1[i] && name1[i] <= 122) {
            name1[i] = name1[i] - 32;  //強制轉大寫
        }
    }
    getchar();
    number = 1;
    for (j = 1; j <= n; j++) {
        scanf("%d ", &length2);  //length2是原本學生名字的長度
        for (i = 1; i <= length2; i++) {
            scanf("%c", &name2[i]);
            if (97 <= name2[i] && name2[i] <= 122) {
                name2[i] = name2[i] - 32;  //強制大寫
            }
        }
        if (length2 > length1) {
            for (i = 1; i <= length1; i++) {
                if (name2[i] > name1[i]) {
                    k = 1;
                    break;
                } else if (name1[i] > name2[i]) {
                    k = 2;
                    break;
                }
            }
        }

        else {
            for (i = 1; i <= length1; i++) {
                if (name2[i] > name1[i]) {
                    k = 1;
                    break;
                } else if (name1[i] > name2[i]) {
                    k = 2;
                    break;
                }
            }
        }
        if (k == 2) number = number + 1;
    }
    printf("%d", number);
}