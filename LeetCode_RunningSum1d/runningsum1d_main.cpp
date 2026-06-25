#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> result;
        result.reserve(nums.size());
        int runningSum = 0;
        for (int x : nums) {
            runningSum += x;
            result.push_back(runningSum);
        }
        return result;      
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = sol.runningSum(nums);
    for (const auto& n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}