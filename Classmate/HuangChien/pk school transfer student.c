#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct student {
    int n;
    char name[16];
};

int main() {
    int N;
    scanf("%d", &N);
    int n;
    char trans_name[16] = {0};
    scanf("%d %s", &n, trans_name);
    for (int i = 0; i < 16; i++) {
        trans_name[i] = tolower(trans_name[i]);
    }
    struct student stu[N];
    int stu_num = N + 1;
    //printf("%d\n",N);
    for (int i = 0; i < N; i++) {
        //printf("%d\n",N);
        scanf("%d %s", &stu[i].n, stu[i].name);
        for (int j = 0; j < 16; j++)
            stu[i].name[j] = tolower(stu[i].name[j]);
    }
    for (int j = 0; j < N; j++)
        if (strcmp(stu[j].name, trans_name) > 0)
            stu_num--;

    printf("%d", stu_num);
    return 0;
}