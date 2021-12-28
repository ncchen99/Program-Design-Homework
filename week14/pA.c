#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int addition(char str[]);

int main() {
    char str[N];
    scanf("%s", str);
    int sum = addition(str);
    printf("%d", sum);
    return 0;
}
int addition(char str[]) {
    char *a = strtok(str, "+");
    int sum = 0;
    while (a != NULL) {
        sum += atoi(a);
        a = strtok(NULL, "+");
    }
    return sum;
}