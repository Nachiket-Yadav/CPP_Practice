#include <vector>
#include <iostream>

class Solution {
public:
void moveZeroes(std::vector<int>& nums) {
    int write = 0;
    for (int scan = 0; scan < nums.size(); ++scan) {
        if (nums[scan] != 0) {
            std::swap(nums[scan], nums[write]);
            ++write;
        }
    }
    }
};


int main() {
    Solution solution;
    std::vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}