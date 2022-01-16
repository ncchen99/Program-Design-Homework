#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define True 1
#define False 0
int main() {
    char temp_c, str[100];
    int i = 0, len = 1;
    do {
        scanf("%c", &temp_c);
        if (temp_c != ' ' && temp_c != '\n')
            str[i++] = temp_c;
    } while (temp_c != ' ' && temp_c != '\n' && i < 21);
    len = i;
    int is_panidrome = True;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            is_panidrome = False;
            break;
        }
    }
    printf("i: %d\n", i);

    if (is_panidrome == True) {
        printf("is a panidrome\n");
    } else {
        printf("not a panidrome\n");
    }
}