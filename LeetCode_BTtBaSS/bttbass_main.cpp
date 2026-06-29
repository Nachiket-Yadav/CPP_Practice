#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = std::numeric_limits<int>::max();
        int maxProfit = 0;

        for (const int& price : prices) { // const ref instead of copy
            minPrice = std::min(minPrice, price);
            maxProfit = std::max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

int main() {
    Solution solution;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = solution.maxProfit(prices);
    std::cout << "Maximum Profit: " << result << std::endl;
    return 0;
}