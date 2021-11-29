#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <stdlib.h>
int n, nums[153];
int cnt[105] = {0};
int ans;

int dfs(int s, int t) {
    if (t > 8)
        return nums[33];
    if (s == n - 1)
        for (int i = 0; i < n; i++)
            if (cnt[nums[i]] > 0)
                return nums[i];
    int cb = 0;
    for (int i = 0; i < n && !cb; i++) {
        if (cnt[nums[i]] > 0) {
            cnt[nums[i]]--;
            for (int j = i - 1; j >= 0 && !cb; j--) {
                if (cnt[nums[j]] > 0) {
                    cnt[nums[j]]--;
                    if (cnt[nums[i] - nums[j]] > 0) {
                        cnt[nums[i] - nums[j]]--;
                        cb |= dfs(s + 3, t + 1);
                        cnt[nums[i] - nums[j]]++;
                    }
                    cnt[nums[j]]++;
                }
            }
            cnt[nums[i]]++;
        }
    }
    return cb;
}
int cmp(const int *a, const int *b) {
    return (*a) > (*b);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        cnt[nums[i]]++;
    }

    qsort(nums, n, sizeof(int), cmp);
    ans = dfs(0, 0);
    printf("%d", ans);
}