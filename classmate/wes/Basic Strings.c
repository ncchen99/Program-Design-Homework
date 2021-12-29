#include <stdio.h>

int main() {
    char str[8192] = {0};
    int length = 0;
    char newstr[8192] = {};
    int newlength = 0;
    while (1) {
        scanf("%c", &str[length]);
        if (str[length] == '\n') {
            break;
        }
        length++;
    }
    int N;
    scanf("%d\n", &N);
    for (int k = 0; k < N; k++) {
        char order[10];
        int order_length = 0;
        while (1) {
            scanf("%c", &order[order_length]);
            if (order[order_length] == '\n') {
                break;
            }
            order_length++;
        }
        if (order[0] == 'R') {
            if (order[2] == 'V') {  //REVERSE
                for (int i = 0; i < length; i++) {
                    newstr[i] = str[length - 1 - i];
                }
                str[length] = '\0';
                for (int i = 0; i < length; i++) {
                    str[i] = newstr[i];
                    printf("%c", str[i]);
                }
                printf("\n");
            } else if (order[2] == 'M') {  //REMOVE
                for (int i = 0; i < length; i++) {
                    if (str[i] != order[7]) {
                        newstr[newlength] = str[i];
                        newlength++;
                    }
                }
                length = newlength;
                newlength = 0;
                str[length] = '\0';
                for (int i = 0; i < length; i++) {
                    str[i] = newstr[i];
                    printf("%c", str[i]);
                }
                printf("\n");
            }
        } else if (order[0] == 'C') {  //COMPRESS
            char now = str[0];
            int nowlength = 1;
            for (int i = 1; i < length; i++) {
                if (str[i] != now) {  //印-(i-1)
                    newstr[newlength] = '-';
                    newlength++;
                    newstr[newlength] = now;
                    newlength++;
                    int number_of_digit = 0;
                    int a[10] = {};
                    while (nowlength > 0) {
                        a[number_of_digit] = nowlength % 10;
                        number_of_digit++;
                        nowlength /= 10;
                    }
                    for (int j = number_of_digit - 1; j >= 0; j--) {
                        newstr[newlength] = '0' + a[j];
                        newlength++;
                    }
                    now = str[i];
                    nowlength = 1;
                } else {
                    nowlength++;
                }
                if (i == length - 1) {
                    newstr[newlength] = '-';
                    newlength++;
                    newstr[newlength] = now;
                    newlength++;
                    int number_of_digit = 0;
                    int a[10];
                    while (nowlength > 0) {
                        a[number_of_digit] = nowlength % 10;
                        number_of_digit++;
                        nowlength /= 10;
                    }
                    for (int j = number_of_digit - 1; j >= 0; j--) {
                        newstr[newlength] = '0' + a[j];
                        newlength++;
                    }
                }
            }
            length = newlength;
            newlength = 0;
            str[length] = '\0';
            for (int i = 0; i < length; i++) {
                str[i] = newstr[i];
                printf("%c", str[i]);
            }
            printf("\n");
        } else if (order[0] == 'T') {
            if (order[3] == 'L') {  //TO_LOWER
                str[length] = '\0';
                for (int i = 0; i < length; i++) {
                    if (str[i] >= 'A' && str[i] <= 'Z') {
                        str[i] += 32;
                    }
                    printf("%c", str[i]);
                }
                printf("\n");
            }
            if (order[3] == 'U') {  //TO_UPPER
                str[length] = '\0';
                for (int i = 0; i < length; i++) {
                    if (str[i] >= 'a' && str[i] <= 'z') {
                        str[i] -= 32;
                    }
                    printf("%c", str[i]);
                }
                printf("\n");
            }
        } else if (order[0] == 'P') {  //PRINT
            str[length] = '\0';
            for (int i = 0; i < length; i++) {
                printf("%c", str[i]);
            }
            printf("\n");
        }
    }
    return 0;
}