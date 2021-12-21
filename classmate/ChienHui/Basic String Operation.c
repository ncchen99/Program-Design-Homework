#include <stdio.h>
#include <string.h>

void PRINT(char str[]);
void REVERSE(char str[]);
void TO_UPPER(char str[]);
void TO_LOWER(char str[]);
void REMOVE(char str[], char target);
void COMPRESS(char str[]);

int main() {
    char order1[] = "PRINT";
    char order2[] = "REVERSE";
    char order3[] = "TO_UPPER";
    char order4[] = "TO_LOWER";
    char order5[] = "REMOVE";
    char order6[] = "COMPRESS";
    char str1[1025];
    gets(str1);
    int N;
    scanf("%d", &N);
    char str2[10];
    int a = 1;
    for (int i = 0; i < N; i++) {
        scanf("%s", str2);
        for (int j = 0; j < strlen(str2); j++) {
            if (str2[j] != order1[j]) {
                a = 0;
                break;
            }
        }
        if (a == 1) {
            PRINT(str1);
            continue;
        } else {
            a = 1;
            for (int j = 0; j < strlen(str2); j++) {
                if (str2[j] != order2[j]) {
                    a = 0;
                    break;
                }
            }
        }
        if (a == 1) {
            REVERSE(str1);
            continue;
        } else {
            a = 1;
            for (int j = 0; j < strlen(str2); j++) {
                if (str2[j] != order3[j]) {
                    a = 0;
                    break;
                }
            }
        }
        if (a == 1) {
            TO_UPPER(str1);
            continue;
        } else {
            a = 1;
            for (int j = 0; j < strlen(str2); j++) {
                if (str2[j] != order4[j]) {
                    a = 0;
                    break;
                }
            }
        }
        if (a == 1) {
            TO_LOWER(str1);
            continue;
        } else {
            a = 1;
            for (int j = 0; j < strlen(str2); j++) {
                if (str2[j] != order5[j]) {
                    a = 0;
                    break;
                }
            }
        }
        if (a == 1) {
            char ch;
            ch = getchar();
            ch = getchar();
            REMOVE(str1, ch);
            continue;
        } else {
            COMPRESS(str1);
        }
    }
    return 0;
}
void PRINT(char str[]) {
    printf("%s\n", str);
}
void REVERSE(char str[]) {
    char temp;
    for (int i = 0; i < strlen(str) / 2; i++) {
        temp = str[i];
        str[i] = str[strlen(str) - 1 - i];
        str[strlen(str) - 1 - i] = temp;
    }
    PRINT(str);
}
void TO_UPPER(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    PRINT(str);
}
void TO_LOWER(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    PRINT(str);
}
void REMOVE(char str[], char target) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == target) {
            for (int j = i; j < strlen(str); j++) {
                str[j] = str[j + 1];
            }
            i--;
        }
    }
    PRINT(str);
}
void COMPRESS(char str[]) {
    int nums[strlen(str)];
    char ch[strlen(str)];
    int i = 0, j = 0;
    for (; i < strlen(str);) {
        ch[j] = str[i];
        nums[j] = 0;
        while (str[i] == ch[j]) {
            nums[j] += 1;
            i++;
        }
        j++;
    }
    ch[j] = '\0';
    int k = 0, m = 0, n = 0;
    do {
        str[k] = '-';
        k++;
        str[k] = ch[m];
        k++;
        m++;
        if (nums[n] < 10) {
            str[k] = nums[n] + 48;
        } else if (nums[n] >= 10 && nums[n] <= 99) {
            str[k] = nums[n] / 10 + 48;
            k++;
            str[k] = nums[n] % 10 + 48;
        } else if (nums[n] >= 100) {
            str[k] = nums[n] / 100 + 48;
            k++;
            str[k] = nums[n] / 10 % 10 + 48;
            k++;
            str[k] = nums[n] % 10 + 48;
        }
        k++;
        n++;
    } while (m < strlen(ch));
    str[k] = '\0';
    PRINT(str);
}