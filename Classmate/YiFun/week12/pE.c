double calculate_score(int CH, int ENG, int *MATH, int SCI, int SS, int *TOTAL) {
    *TOTAL = CH + ENG + *MATH + SCI + SS;
    return *TOTAL / 5.0;
}