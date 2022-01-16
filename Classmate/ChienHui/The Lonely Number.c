#include <stdbool.h>
#include <stdio.h>
int theNumber(int nums[], int n);

int main() {
    int n;
    scanf("%d", &n);
    int number[100] = {};
    for (int i = 0; i < n; i++)
        scanf("%d", &number[i]);
    printf("%d\n", theNumber(number, n));
    return 0;
}

int theNumber(int nums[], int n) {
    if (n == 1)
        return nums[0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int group[200] = {0}, newNums[100] = {0};
            for (int k = 0; k < n; k++)
                group[nums[k]]++;
            if (group[nums[i]] && group[nums[j]] && group[nums[i] + nums[j]] && i != j) {
                group[nums[i]]--;
                group[nums[j]]--;
                group[nums[i] + nums[j]]--;
                for (int ii = 100, k = 0; ii >= 1; ii--)
                    if (group[ii])
                        for (int jj = 0; jj < group[ii]; jj++)
                            newNums[k++] = ii;
                int res = theNumber(newNums, n - 3);
                if (res) return res;
            }
        }
    }
    return 0;
}