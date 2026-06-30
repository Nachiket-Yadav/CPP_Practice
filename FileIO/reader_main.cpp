#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

int main(){

    double maxValue = -2.0; // Define the maximum value for comparison
    int count = 0; // Counter for the number of values read

    std::ifstream in("nums.csv"); // opens (creates/overwrites) a csv

    if (!in) { // Check if file is opened successfully
        std::cerr << "Failed to open file";
        return 1;
    }

    std::string line;
    while(std::getline(in,line)){

        std::stringstream ss(line); // treat the line as a stream        
        std::string indexCell, valueCell;

        std::getline(ss,indexCell,','); // read the index cell
        std::getline(ss,valueCell,','); // read the value cell

        int index = std::stoi(indexCell); // convert index to int
        double value = std::stod(valueCell); // convert value to double

        if(value > maxValue){ // compare the value with maxValue
            maxValue = value; // update maxValue if the current value is greater
        }

        ++count; // increment the counter for each value read
    }

    std::cout << "Read " << count << " rows\n";
    std::cout << "Max sine value: " << maxValue << "\n";

    return 0;
}