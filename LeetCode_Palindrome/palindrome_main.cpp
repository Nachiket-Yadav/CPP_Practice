#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::cout << sol.isPalindrome(121) << std::endl;  // Output: 1 (true)
    std::cout << sol.isPalindrome(-121) << std::endl; // Output: 0 (false)
    std::cout << sol.isPalindrome(10) << std::endl;   // Output: 0 (false)
    return 0;
}