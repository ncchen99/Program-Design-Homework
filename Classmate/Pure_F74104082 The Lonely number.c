#include <stdio.h>
int n;

int lonely_num(int arr[], int k) {
    if (arr[k] == 0)
        return lonely_num(arr, k + 1);
    int times = 0;
    for (int j = 0; j < n; j++) {
        if (arr[j] != 0) {
            times++;
        }
    }
    if (times == 1) { /*找看有沒有lonely number了(若times==1，即只剩一個數*/
        for (int j = 0; j < n; j++) {
            if (arr[j] != 0) return arr[j];
        }
    }
    for (int l = 0; l < n; l++) { /*配對*/
        for (int i = 0; i < n; i++) {
            if (i != k && l != k && i != l && arr[i] != 0 && arr[l] != 0) {
                if (arr[k] + arr[l] == arr[i] || arr[i] + arr[l] == arr[k]) {
                    int ta = arr[k], tb = arr[l], tc = arr[i];
                    arr[k] = 0;
                    arr[l] = 0;
                    arr[i] = 0;
                    int r = lonely_num(arr, k + 1);
                    if (r) return r;
                    arr[k] = ta;
                    arr[l] = tb;
                    arr[i] = tc;
                }
            }
        }
    }
    return 0;
}

int main() {
    int arr[500] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        int a = lonely_num(arr, i);
        if (a) {
            printf("%d", a);
            return 0;
        }
    }
}