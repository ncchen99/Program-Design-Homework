#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    char *name[102], name2[102][101] = {};
    for (int i = 0; i < n; i++) {
        name[i] = malloc(sizeof(char) * 101);
        scanf("%s", name[i]);
        strcpy(name2[i], name[i]);
        for (int j = 0; j < strlen(name2[i]); j++)
            name2[i][j] = tolower(name2[i][j]);
        // printf("name2:%s\n", name2[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(name2[i], name2[j]) > 0) {
                char *temp2 = name[j];
                name[j] = name[i];
                name[i] = temp2;
                char *temp = (char *)malloc((strlen(name2[i]) + 1) * sizeof(char));
                strcpy(temp, name2[i]);
                strcpy(name2[i], name2[j]);
                strcpy(name2[j], temp);
                // free(temp);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", name[i]);
    }

    return 0;
}
