#include <stdio.h>
void reverse(char str[]);
void Remove(char str[]);
void compress(char str[]);
int long_of_str;
char command[25] = {0};
int main() {
    char str[8000] = {0};
    int i = 0, num;
    char a = '1';
    while (a != '\n') {
        a = getchar();
        if (a != '\n') {
            str[i] = a;
            i++;
        }
    }
    long_of_str = i;
    scanf("%d", &num);
    char cd = getchar();
    while (num > 0) {
        scanf("%s", command);
        if (command[3] == 'O') {
            char cd = getchar();
            Remove(str);
            num--;
        } /*remove*/
        else if (command[3] == 'N') {
            char cd = getchar();
            printf("%s\n", str);
            num--;
        } /*print*/
        else if (command[3] == 'U') {
            char cd = getchar();
            for (int i = 0; i < long_of_str; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str[i] = str[i] - 'a' + 'A';
                }
            }
            printf("%s\n", str);
            num--;
        } /*to_upper*/
        else if (command[3] == 'L') {
            char cd = getchar();
            for (int i = 0; i < long_of_str; i++) {
                if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] = str[i] - 'A' + 'a';
            }
            printf("%s\n", str);
            num--;
        } /*to_lower*/
        else if (command[3] == 'E') {
            char cd = getchar();
            reverse(str);
            num--;
        } /*reverse*/
        else if (command[3] == 'P') {
            char cd = getchar();
            compress(str);
            num--;
        } /*compress*/
        for (int s = 0; s < 25; s++) {
            command[s] = 'a';
        }
    }
    return 0;
}
void reverse(char str[]) {
    char str_reference[8000] = {0};
    int a = long_of_str;
    for (int i = 0; long_of_str >= 1; i++) {
        str_reference[i] = str[--long_of_str];
    }
    for (int i = 0; i < a; i++) {
        str[i] = str_reference[i];
    }
    printf("%s\n", str);
    long_of_str = a; /*不知道為什麼把這行變註解就不會TLE*/
    return;
}
void Remove(char str[]) {
    char move = getchar();
    int a, b = 0;
    char tmp[8000] = {};
    for (int i = 0; i < long_of_str; i++) {
        if (move != str[i])
            tmp[b++] = str[i];
    }
    tmp[b] = '\0';
    for (int i = 0; i <= b; i++) {
        str[i] = tmp[i];
    }
    printf("%s\n", str);
    long_of_str = b;
    return;
}
void compress(char str[]) {
    char compare[8000] = {0};
    int a = 0, v = 0;
    char c;
    for (int i = 0; i < long_of_str; i++) {
        a = 0;
        c = str[i];
        while (str[i] == c) {
            a++;
            i++;
        }
        i--;
        compare[v++] = '-';
        compare[v++] = c;
        if (a <= 9)
            compare[v++] = a + 48;
        else if (a < 100) {
            compare[v++] = a / 10 + 48;
            compare[v++] = a % 10 + 48;
        } else if (a < 1000) {
            compare[v++] = a / 10 / 10 + 48;
            compare[v++] = a / 10 % 10 + 48;
            compare[v++] = a % 10 + 48;
        } else {
            compare[v++] = '1';
            compare[v++] = a / 10 / 10 % 10 + 48;
            compare[v++] = a / 10 % 10 + 48;
            compare[v++] = a % 10 + 48;
        }
    }
    for (int i = 0; i < v; i++)
        str[i] = compare[i];
    printf("%s\n", str);
    long_of_str = v;
    return;
}