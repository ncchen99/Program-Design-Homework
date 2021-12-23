#include <stdbool.h>
#include <stdio.h>
#include <string.h>
unsigned int length;
int compress_index = 0;
void print(char string[16000]);
void reverse(char string[16000]);
void to_upper(char string[16000]);
void to_lower(char string[16000]);
void _remove(char string[16000], char target);
void compress(char string[16000], char temp[16000], int location, int k);
int main() {
    char string[16000], str2[100];
    int n, m = 0;
    while (scanf("%c", &string[m]) != EOF) {
        if (string[m] == '\n') break;
        m++;
    }

    length = m;
    scanf("%d", &n);
    for (; n > 0; n--) {
        scanf("%s", str2);
        getchar();
        if (strcmp(str2, "PRINT") == 0)
            print(string);
        else if (strcmp(str2, "REVERSE") == 0)
            reverse(string);
        else if (strcmp(str2, "TO_UPPER") == 0)
            to_upper(string);
        else if (strcmp(str2, "TO_LOWER") == 0)
            to_lower(string);
        else if (strcmp(str2, "REMOVE") == 0) {
            char target;
            getchar();
            scanf("%c", &target);
            _remove(string, target);
        } else if (strcmp(str2, "COMPRESS") == 0) {
            char temp[16000];
            int i, k = 1;
            temp[compress_index] = '-';
            compress_index++;
            temp[compress_index] = string[0];
            compress(string, temp, 0, 1);
            length = compress_index + 1;
            for (i = 0; i < length; i++) {
                string[i] = temp[i];
            }
            for (i = 0; i < length; i++) {
                printf("%c", string[i]);
            }
            printf("\n");
            compress_index = 0;
        }
    }
    return 0;
}
void print(char string[16000]) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}
void reverse(char string[16000]) {
    int i, j = 0;
    char temp[16000];
    for (i = 0; i < length; i++) {
        temp[i] = string[i];
    }
    for (i = i - 1; i >= 0; i--) {
        string[j] = temp[i];
        j++;
    }
    for (i = 0; i < length; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}
void to_upper(char string[16000]) {
    int i;
    for (i = 0; i < length; i++) {
        if ('a' <= string[i] && string[i] <= 'z') {
            string[i] -= 32;
        }
    }
    for (i = 0; i < length; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}
void to_lower(char string[16000]) {
    int i;
    for (i = 0; i < length; i++) {
        if ('A' <= string[i] && string[i] <= 'Z') {
            string[i] += 32;
        }
    }
    for (i = 0; i < length; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}
void _remove(char string[16000], char target) {
    bool storage[16000] = {0};
    int i, j = 0;
    char temp[16000];
    for (i = 0; i < length; i++) {
        temp[i] = string[i];
    }
    for (i = 0; i < length; i++) {
        if (temp[i] == target) storage[i] = 1;
    }
    for (i = 0; i < length; i++) {
        if (!storage[i]) {
            string[j] = temp[i];
            printf("%c", string[j]);
            j++;
        }
    }
    printf("\n");
    length = j;
}
void compress(char string[16000], char temp[], int location, int k) {
    if (location + 1 >= length) {
        compress_index++;
        if (k < 10) {
            temp[compress_index] = k + 48;
        }
        if (k > 9) {
            temp[compress_index] = k / 10 + 48;
            compress_index++;
            temp[compress_index] = k % 10 + 48;
        } else if (k > 99) {
            temp[compress_index] = k / 100 + 48;
            compress_index++;
            temp[compress_index] = (k / 10) % 10 + 48;
            compress_index++;
            temp[compress_index] = k % 10 + 48;
        } else if (k > 999) {
            temp[compress_index] = k / 1000 + 48;
            compress_index++;
            temp[compress_index] = (k / 100) % 10 + 48;
            compress_index++;
            temp[compress_index] = (k / 10) % 10 + 48;
            compress_index++;
            temp[compress_index] = k % 10 + 48;
        }
        return;
    }
    if (string[location] == string[location + 1]) {
        k++;
        compress(string, temp, location + 1, k);
    } else {
        compress_index++;
        if (k < 10) {
            temp[compress_index] = k + 48;
        }
        if (k > 9) {
            temp[compress_index] = k / 10 + 48;
            compress_index++;
            temp[compress_index] = k % 10 + 48;
        } else if (k > 99) {
            temp[compress_index] = k / 100 + 48;
            compress_index++;
            temp[compress_index] = (k / 10) % 10 + 48;
            compress_index++;
            temp[compress_index] = k % 10 + 48;
        } else if (k > 999) {
            temp[compress_index] = k / 1000 + 48;
            compress_index++;
            temp[compress_index] = (k / 100) % 10 + 48;
            compress_index++;
            temp[compress_index] = (k / 10) % 10 + 48;
            compress_index++;
            temp[compress_index] = k % 10 + 48;
        }
        compress_index += 1;
        temp[compress_index] = '-';
        compress_index += 1;
        temp[compress_index] = string[location + 1];
        compress(string, temp, location + 1, 1);
    }
}