#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct weight {
    char chapter[10];
    int percent;
};

struct score {
    char chapter[10];
    int score;
};

struct report_card {
    char name[32];
    struct score record[10];
    int final;
    int max_score;
    int min_score;
};

void calculate(struct report_card[], struct weight[], int student_num, int chapter_num);

int main() {
    int student_num, chapter_num;
    struct weight chapter[10];
    struct report_card card[100];

    scanf("%d %d\n", &chapter_num, &student_num);
    for (int i = 0; i < chapter_num; ++i) {
        scanf("%d %s", &chapter[i].percent, chapter[i].chapter);
    }

    for (int i = 0; i < student_num; ++i) {
        scanf("%s", card[i].name);
        for (int j = 0; j < chapter_num; ++j) {
            scanf("%d %s", &card[i].record[j].score, card[i].record[j].chapter);
        }
    }

    calculate(card, chapter, student_num, chapter_num);

    for (int i = 0; i < student_num; ++i) {
        printf("%s %d %d %d\n", card[i].name, card[i].final, card[i].max_score, card[i].min_score);
    }
}

int cmp(struct weight* a, struct weight* b) {
    return strcmp(a->chapter, b->chapter);
}
// int cmp2(struct score* a, struct score* b) {
//     return strcmp(a->chapter, b->chapter);
// }
void calculate(struct report_card card[], struct weight chapter[], int student_num, int chapter_num) {
    qsort(chapter, chapter_num, sizeof(chapter[0]), cmp);
    for (int i = 0; i < student_num; i++)
        qsort(card[i].record, chapter_num, sizeof(card[i].record[1]), cmp);
    for (int i = 0; i < student_num; i++) {
        card[i].final = 0;
        card[i].max_score = 0;
        card[i].min_score = 10000;
        for (int j = 0; j < chapter_num; j++) {
            card[i].final += chapter[j].percent * card[i].record[j].score;
            card[i].max_score = (card[i].max_score < card[i].record[j].score ? card[i].record[j].score : card[i].max_score);
            card[i].min_score = (card[i].min_score < card[i].record[j].score ? card[i].min_score : card[i].record[j].score);
        }
        card[i].final /= 100;
    }
}
