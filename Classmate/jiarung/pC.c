#include <stdio.h>
#include <stdlib.h>
int main() {
    int m, d, initd = 5;  // 2021 ?ç¬¬ä¸å¤©æ¯?¨ä?
    char r[7][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int mtod[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d/%d", &m, &d);

    if (m < 1 || m > 12 || d < 1 || d > mtod[m - 1]) {
        printf("Input Error");
        return 0;
    }

    for (int i = 0; i < m - 1; i++)
        d += mtod[i];

    d += initd;
    printf("%s", r[d % 7 - 1]);
    system("pause");
    return 0;
}