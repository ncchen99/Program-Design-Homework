#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char** std, char** std1) {
    char* tmp = *std;
    *std = *std1;
    *std1 = tmp;
}
int main() {
    int std_num, res;
    scanf("%d\n", &std_num);
    char* std[100];
    for (int i = 0; i < std_num; i++) {
        std[i] = malloc(100);
        scanf("%s", std[i]);
    }
    for (int i = 0, std_num_tmp = std_num; i < std_num_tmp - 1;) {
        char ta[100] = {}, tb[100] = {};
        int maxlen = 0;
        if (strlen(std[i]) > strlen(std[i + 1]))
            maxlen = strlen(std[i]);
        else
            maxlen = strlen(std[i + 1]);
        for (int j = 0; j < maxlen; j++) {
            ta[j] = tolower(std[i][j]);
            tb[j] = tolower(std[i + 1][j]);
        }
        // printf("ta:%s, tb:%s\n", ta, tb);
        res = strcmp(ta, tb);
        if (res > 0) {
            // printf("swapping:%s <=> %s \n", std[i], std[i + 1]);
            swap(&std[i], &std[i + 1]);
            // printf("swap finish!!\n");
        }
        if ((i + 1) == std_num_tmp - 1) {
            // printf("ROUND:%d\n", std_num_tmp);
            i = 0;
            std_num_tmp--;
            continue;
        }
        i++;
    }
    for (int i = 0; i < std_num; i++) {
        printf("%s\n", std[i]);
    }

    return 0;
}
