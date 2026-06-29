#include <iostream>
#include <vector>
#include <algorithm>

// Sort-based solution to check for duplicates in a vector of integers.
// Uses less space than the hash set approach, but has a time complexity of O(n log n) due to sorting.

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for (size_t i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5, 1};
    bool result = solution.containsDuplicate(nums);
    std::cout << (result ? "Contains duplicate" : "No duplicates") << std::endl;
    return 0;
}