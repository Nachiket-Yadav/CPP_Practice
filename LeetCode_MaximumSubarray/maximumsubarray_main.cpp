#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];
    for (std::size_t i = 1; i < nums.size(); ++i) {
        const int& x = nums[i];                       // const ref instead of copy
        maxEndingHere = std::max(x, maxEndingHere + x); // Kadane's algorithm
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
};

int main() {
    Solution solution;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = solution.maxSubArray(nums);
    std::cout << "Maximum Subarray Sum: " << result << std::endl;
    return 0;
}