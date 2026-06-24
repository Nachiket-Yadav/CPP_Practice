#include <iostream>

int main() {

    int a = 5;
    int b = 6;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    int d {7}, e {8};
    std::cout << "d = " << d << ", e = " << e << std::endl;

    int f = 9, g = 10;

    std::cout << "f = " << f << ", g = " << g << std::endl;

    [[maybe_unused]] int h = 11, i = 12;

    int x {};
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "x = " << x << "\n";

    return 0;

}
