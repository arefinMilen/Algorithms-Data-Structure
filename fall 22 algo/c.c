#include <stdio.h>
#include <string.h>

#define MAX_N 105
#define MAX_W 100005

int wt[MAX_N], val[MAX_N];
long long dp[MAX_N][MAX_W];

long long solve(int index, int wt_left) {
    if (wt_left == 0)
        return 0;
    if (index < 0)
        return 0;
    if (dp[index][wt_left] != -1)
        return dp[index][wt_left];

    long long result = solve(index - 1, wt_left);
    if (wt_left - wt[index] >= 0)
        result = (result > solve(index - 1, wt_left - wt[index]) + val[index]) ? result : (solve(index - 1, wt_left - wt[index]) + val[index]);

    return dp[index][wt_left] = result;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, a;
    scanf("%d %d", &n, &a);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &wt[i], &val[i]);

    long long x = solve(n - 1, a);
    printf("%lld\n", x);
    return 0;
}

