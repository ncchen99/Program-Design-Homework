#include <stdio.h>
#include <stdlib.h>
#define data 20005
void hex_terminal(int sum);
void devide(short b[], int size) { /*把奇數和和偶數和算出來*/
    if (size == 1) {
        printf("%x", b[0]);
        return;
    }
    int i = 0;
    int sum_odd = 0, sum_even = 0;
    for (i = 1; i <= size - 1; i += 2) { /*奇數和*/
        sum_odd += b[i];
    }
    for (i = 0; i <= size - 1; i += 2) { /*偶數和*/
        sum_even += b[i];
    }
    hex_terminal(sum_odd);
    hex_terminal(sum_even);
}
void hex_terminal(int sum) { /*換十六進位並輸出*/
    int sumt = sum, cd = 0;
    while (sumt != 0) {
        sumt /= 16;
        cd++;
    }
    short b[100] = {};
    // char dict[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    for (int i = cd - 1; i >= 0; i--) {
        b[i] = sum % 16;
        sum /= 16;
    }
    // printf("cd:%d, b[]:%s\n", cd, b);
    devide(b, cd);
    free(b);
}
int main() {
    short b[20000];
    int i;
    for (i = 0;; i++)
        if (scanf("%1x", &b[i]) == EOF)
            break;

    // printf("i:%d\nb:%s\n", i, b);
    devide(b, i);
    return 0;
}