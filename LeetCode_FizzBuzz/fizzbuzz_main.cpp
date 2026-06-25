#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> answer;
        
        for (int i =1; i <= n; i++) {
            std::string current = "";

            if (i % 3 == 0) {
                current += "Fizz";
            }
            if (i % 5 == 0) {
                current += "Buzz";
            }

            if (current.empty()) {
                answer.push_back(std::to_string(i));
            } else {
                answer.push_back(current);
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> result = sol.fizzBuzz(15);
    for (const auto& s : result) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}