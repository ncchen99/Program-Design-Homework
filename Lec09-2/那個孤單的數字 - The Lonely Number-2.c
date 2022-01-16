#include <stdio.h>
#include <stdlib.h>
int cmp(const int *a, const int *b) {
    return (*a) > (*b);
}
int main() {
    int n, nums[153];
    int cnt[105] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        cnt[nums[i]]++;
    }

    qsort(nums, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        if (!cnt[nums[i]]) continue;
        // printf("%d ", nums[i]);
        for (int j = 0; j < i; j++) {
            if (!cnt[nums[j]] && !cnt[nums[i]]) continue;
            int lb = 0, rb = j - 1, tar = nums[i] - nums[j];
            while (lb <= rb) {
                int mb = lb + rb >> 1;
                if (nums[mb] < tar)
                    lb = mb + 1;
                else
                    rb = mb - 1;
            }
            printf("%d:%d %d:%d i:%d j:%d %d\n", lb, nums[lb], rb, nums[rb], i, j, tar);
            if ((nums[lb] == tar || rb >= 0 ? nums[rb] == tar : 0) && nums[j] == tar ? cnt > 1 : cnt[tar] > 0) {
                                cnt[tar]--;
                cnt[nums[i]]--;
                cnt[nums[j]]--;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        printf("%d ", cnt[i]);
        if (cnt[i] > 0) ans = i;
    }
    printf("%d", ans);
}