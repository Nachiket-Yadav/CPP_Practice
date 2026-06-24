#include <iostream>

int getUserInput() {
    int input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    return input;
}

void printUserInput(int input) {
    std::cout << "User input: " << input << std::endl;
}

void multiplyTwo(int a) {
    std::cout << "Product: " << a * 2 << std::endl;
}

int main() {
    int userInput {getUserInput()};
    printUserInput(userInput);
    multiplyTwo(userInput);
    return 0;
}