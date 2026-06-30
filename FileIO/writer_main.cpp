#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

int main(){

    std::ofstream out("nums.csv"); // opens (creates/overwrites) a csv

    if (!out) { // Check if file is opened successfully
        std::cerr << "Failed to open file";
        return 1;
    }

    for (int i = 0; i < 1000; i++) {

        double rad = i * 0.01; // radians
        double sin_val = std::sin(rad);

        out << i << "," << std::fixed << std::setprecision(10) << sin_val << "\n"; // write index and sine value to the file
    
    }
    out.close(); // close the file after

    return 0;
}