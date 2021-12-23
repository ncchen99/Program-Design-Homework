#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#define swap(a, b)        \
    {                     \
        double *temp = a; \
        a = b;            \
        b = temp;         \
    }
void quicksort(double *position[], int low, int high);
int getmiddle(double *position[], int low, int high);
int main() {
    struct data {
        char name[1000];
        int p;
        int l;
        int w;
        int r;
        double recommend;
    } youtuber[52];
    int n, i;
    double sort[52], *position[52];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", youtuber[i].name);
        scanf("%d%d%d%d", &(youtuber[i].p), &(youtuber[i].l), &(youtuber[i].w), &(youtuber[i].r));
        // printf("%d %d %d %d ", (youtuber[i].p), (youtuber[i].l), (youtuber[i].w), (youtuber[i].r));
        youtuber[i]
            .recommend = (double)(youtuber[i].p) * ((double)(youtuber[i].w) / (double)(youtuber[i].l)) * (double)(youtuber[i].r);
        sort[i] = youtuber[i].recommend;
        // printf("%lf\n", sort[i]);
        position[i] = &sort[i];
    }
    quicksort(position, 0, n - 1);
    for (i = 0; i < n; i++) {
        int index = (position[i] - &sort[0]);
        //printf("%d\n", index);
        //printf("position[%d]=%hx *position[%d]=%d \n", i, position[i], i, *position[i]);
        printf("%s\n", youtuber[index].name);
    }
    return 0;
}
void quicksort(double *position[], int low, int high) {
    if (low >= high) return;
    int middle = getmiddle(position, low, high);
    quicksort(position, 0, middle - 1);
    quicksort(position, middle + 1, high);
}
int getmiddle(double *position[], int low, int high) {
    int i = low;
    double part = *position[high];
    while (1) {
        while (i <= high && *position[i] < part) i++;
        swap(position[low], position[i]);  //如果比較大就交換他們的位置，這樣排序完就可以知道每個值分別屬於第幾個輸入
        if (i >= high) break;
        low++;
        i++;
    }
    return low;
}