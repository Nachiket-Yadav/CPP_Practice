#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            std::swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};

int main() {
    Solution solution;
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s);
    for (char c : s) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return 0;
}