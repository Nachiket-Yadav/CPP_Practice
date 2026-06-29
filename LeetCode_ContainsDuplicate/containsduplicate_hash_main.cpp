#include <iostream>
#include <vector>
#include <unordered_set>

// Hash set-based solution to check for duplicates in a vector of integers.
// Uses O(n) space but has a time complexity of O(n) due to the single pass through the vector.

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
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