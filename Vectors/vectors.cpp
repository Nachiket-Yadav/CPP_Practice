#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void f(std::vector<double> v){}         // BY VALUE — copies the ENTIRE vector. Wasteful.
void f(std::vector<double>& v){}        // BY REFERENCE — no copy; function CAN modify caller's vector
void f(const std::vector<double>& v){}   // BY CONST REFERENCE — no copy, and CANNOT modify. ← default choice

int main(){
    // different vector initialization methods

    std::vector<int> vec1; //empty vector
    std::vector<int> vec2(5); // vector of size 5 with default values of zero
    std::vector<int> vec3(5, 10); // vector of size 5 with all values initialized to 10
    std::vector<int> vec4 = {1, 2, 3, 4, 5}; // vector initialized with a list of values
    std::vector<int> vec5(vec4); // vector initialized as a copy of another vector


    // essential vector operations
    vec4.push_back(6); // adds an element to the end of the vector
    vec4.pop_back(); // removes the last element of the vector
    vec4.size(); // returns the number of elements in the vector
    vec4[1]; // access the element at index i
    vec4.at(1); // access the element at index i with bounds checking
    vec4.front(); // access the first element of the vector
    vec4.back(); // access the last element of the vector
    vec4.empty(); // checks if the vector is empty
    vec4.clear(); // removes all elements from the vector
    vec4.reserve(10); // reserves space for at least 10 elements in the vector


    // index based access to vector elements

    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    for (std::size_t i =0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    // range based for loop to access vector elements

    for(int x : vec) {
        std::cout << x << " "; // created copy of elements
    }

    for(int& x : vec) {
        x += 5; // uses references to modify the elements of the vector
    }

    for (const int& x : vec){
        std::cout << x << " "; // references make no copy of elements; const prevents modification of the elements
    }

    // using iterators to access vector elements

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " "; // dereferencing the iterator to access the value
    }

    // Passing vectors to functions
    void f(std::vector<double> v);          // BY VALUE — copies the ENTIRE vector. Wasteful.
    void f(std::vector<double>& v);         // BY REFERENCE — no copy; function CAN modify caller's vector
    void f(const std::vector<double>& v);   // BY CONST REFERENCE — no copy, and CANNOT modify. ← default choice

    // STL algorithms

    std::vector<int> vec6 = {1, 3, 2, 4, 5};
    std::vector<double> vec7 = {1.1, 3.3, 2.2, 4.4, 5.5};

    std::sort(vec6.begin(), vec6.end()); // sorts the vector in ascending order. Sorts in place O(n log n) time complexity
    std::sort(vec6.begin(), vec6.end(), std::greater<int>()); // sorts the vector in descending order

    int total = std::accumulate(vec6.begin(), vec6.end(),0); // calculates the sum of all elements in the vector, start value at 0.
    double total2 = std::accumulate(vec7.begin(), vec7.end(), 0.0); // calculates the sum of all elements in the vector, start value at 0.0 to make sure the result is a double.

    double m = std::max(5.0,5.5); // returns the maximum of two values
    auto it = std::max_element(vec6.begin(), vec6.end()); // returns an iterator to the maximum element in the vector
    double biggest = *it; // dereferencing the iterator to get the value of the maximum element

    std::find(vec6.begin(), vec6.end(), 3); // returns an iterator to the first occurrence of the value 3 in the vector, or vec6.end() if not found
    std::reverse(vec6.begin(), vec6.end()); // reverses the order of the elements in the vector

    return 0;
}