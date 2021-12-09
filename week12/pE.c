#include <stdio.h>

double calculate_score(int, int, int *, int, int, int *);

int main(void) {
    int chinese, english, math, science, social_studies;
    scanf("%d %d %d %d %d", &chinese, &english, &math, &science, &social_studies);
    int total = 0;
    double average = calculate_score(chinese, english, &math, science, social_studies, &total);
    printf("%d %.1lf", total, average);
    return 0;
}

double calculate_score(int CH, int ENG, int *MATH, int SCI, int SS, int *TOTAL) {
    *TOTAL = CH + ENG + *MATH + SCI + SS;
    return *TOTAL / (double)5;
}