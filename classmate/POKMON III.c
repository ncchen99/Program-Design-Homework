#include <stdio.h>
#define ALPHA_NUM 26
void main() {
    int n;
    long plain[1001] = {0};
    char alpha;
    long num;
    scanf("%d", &n);
    while (n > 0) {
        scanf("%ld %c", &num, &alpha);
        if (alpha >= 'A' && alpha <= 'Z') {
            plain[alpha - 'A'] = num;
        }
        n--;
    }
    for (char a = 'A'; a <= 'Z'; a++) {
        if (plain[a - 'A'] != 0) {
            printf("Plan %c is in box %ld.\n", a, plain[a - 'A']);
        } else {
            printf("Not found plan %c.\n", a);
        }
    }
}