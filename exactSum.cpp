#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    while (std::cin >> n) {
        std::vector<int> prices(n);
        std::unordered_map<int, int> price_to_index;

        for (int i = 0; i < n; ++i) {
            std::cin >> prices[i];
            price_to_index[prices[i]] = i;
        }

        int m;
        std::cin >> m;


        int book1 = -1, book2 = -1;

        for (int i = 0; i < n; ++i) {
            int remaining = m - prices[i];
            if (price_to_index.find(remaining) != price_to_index.end() && price_to_index[remaining] != i) {
                if (book1 == -1 || abs(prices[i] - remaining) < abs(book1 - book2)) {
                    book1 = std::min(prices[i], remaining);
                    book2 = std::max(prices[i], remaining);
                }
            }
        }

        std::cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << "." << std::endl << std::endl;
    }

    return 0;
}
