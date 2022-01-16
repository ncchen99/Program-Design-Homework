#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapStr(char *a, char *b) {
    char *temp = (char *)malloc((strlen(a) + 1) * sizeof(char));
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
    free(temp);
}

int main() {
    char city[100][100];
    int i = 0;
    while (scanf("%s", city[i])) {
        if (city[i][0] == '-' && city[i][1] == '1')
            break;
        printf("%s", city[i]);
        i++;
    }
    printf("i = %d", i);
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; j++) {
            if (strcmp(city[k], city[j])) {
            }
            // swap
            // swapStr(city[k], city[j]);
        }
    }
    for (int j = 0; j < i; j++) {
        printf("%s ", city[j]);
    }
}