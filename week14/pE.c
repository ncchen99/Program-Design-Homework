#include <stdbool.h>
#include <stdio.h>
#include <string.h>
void lineup_again(char line[]);
void swap(char *a, char *b);
void reverse_caterpillar(char *l, char *r);

int main() {
    char line[1000000];
    scanf("%s", line);
    lineup_again(line);
    printf("%s", line);
}
void swap(char *a, char *b) {
}

void reverse_caterpillar(char *l, char *r) {
}

void lineup_again(char line[]) {
    for (int i = 0; i < strlen(line);) {
        if (line[i] == 'A')
            while (line[i] != 'Z')
                i++;
        else if (line[i] == 'Z') {
            char tmp[100000];
            int k = 0;
            while (line[i - 1] != 'A')
                tmp[k++] = line[i++];
            // printf("%s\n", tmp);
            for (int w = k - 1, t = i - k; w >= 0; w--, t++)
                line[t] = tmp[w];
            i--;
        }
        i++;
    }
}