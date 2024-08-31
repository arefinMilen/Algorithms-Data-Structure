#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;

        std::vector<int> coins(m);
        int totalSum = 0;

        for (int j = 0; j < m; ++j) {
            std::cin >> coins[j];
            totalSum += coins[j];
        }
        std::vector<bool> possible(totalSum + 1, false);
        possible[0] = true;

        for (int j = 0; j < m; ++j) {
            for (int k = totalSum; k >= coins[j]; --k) {
                if (possible[k - coins[j]]) {
                    possible[k] = true;
                }
            }
        }
        int minDifference = totalSum;
        for (int j = totalSum / 2; j >= 0; --j) {
            if (possible[j]) {
                minDifference = totalSum - 2 * j;
                break;
            }
        }
        std::cout << minDifference << std::endl;
    }
    return 0;
}
