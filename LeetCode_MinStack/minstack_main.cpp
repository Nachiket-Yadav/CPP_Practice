#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class MinStack {
private:
    std::vector<int> stack;
    std::vector<int> minStack;
public:
    
    MinStack() {}
    
    void push(int value) {
        stack.push_back(value);
        if (minStack.empty() || value <= minStack.back()) {
            minStack.push_back(value);
        }
    }
    
    void pop() {
        if (!stack.empty()) {

            int popped = stack.back();
            stack.pop_back();

            if (popped == minStack.back()) {
                minStack.pop_back();
            }
        }
        
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    std::cout << "Minimum: " << obj->getMin() << std::endl; // Returns -3
    obj->pop();
    std::cout << "Top: " << obj->top() << std::endl; // Returns 0
    std::cout << "Minimum: " << obj->getMin() << std::endl; // Returns -2

    delete obj;
    return 0;
 }