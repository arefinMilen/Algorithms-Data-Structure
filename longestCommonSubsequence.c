#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubsequence(char str1[], char str2[], int len1, int len2) {
    int dp[MAX_LENGTH][MAX_LENGTH],i,j;

    for ( i = 0; i <= len1; i++) {
        for ( j = 0; j <= len2; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[len1][len2];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int len1, len2;

    while (fgets(str1, MAX_LENGTH, stdin) != NULL && fgets(str2, MAX_LENGTH, stdin) != NULL) {
        len1 = strlen(str1) - 1;
        len2 = strlen(str2) - 1;

        int result = longestCommonSubsequence(str1, str2, len1, len2);
        printf("%d\n", result);
    }

    return 0;
}
