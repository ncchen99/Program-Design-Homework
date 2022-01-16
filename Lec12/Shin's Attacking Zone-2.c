#include <math.h>
#include <stdio.h>

#define MAX_N 1024
#define PI 3.14159265
void convert_to_polar(int *coords, int N);

int main() {
    int N, coords[MAX_N + 1][2];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d%d", &coords[i][0], &coords[i][1]);

    convert_to_polar((int *)coords, N);

    return 0;
}

void convert_to_polar(int *coords, int N) {
    int *point[N];
    for (int *i = coords, k = 0; i < coords + 2 * N; i += 2, k++)
        point[k] = i;
    for (int i = 0; i < N; i++)
        printf("%.2lf %.2lf\n", atan2((double)point[i][1], (double)point[i][0]) * 180 / PI < 0 ? 360 + atan2((double)point[i][1], (double)point[i][0]) * 180 / PI : atan2((double)point[i][1], (double)point[i][0]) * 180 / PI, sqrt((double)point[i][0] * (double)point[i][0] + (double)point[i][1] * (double)point[i][1]));
}