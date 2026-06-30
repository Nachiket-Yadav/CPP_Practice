#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

/*
std::ofstream  // OUTPUT file stream — write TO a file
std::ifstream  // INPUT file stream — read FROM a file
std::fstream    // both (less common; use the specific one)
*/

int main() {

    // Write to a file

    std::ofstream out("data.csv"); // opens (creates/overwrites) a csv
    if (!out) { // Always check if the file opened
        std::cerr << "Failed to open file";
        return 1;
    }
    out << "hello\n"; // writes exactly like std::cout
    out << 42 << "," << 3.13 << "\n";
    out.close(); // usually happens automatically when out is 'out' of scope but good practice

    // Read from a file

    std::ifstream in("data.csv");
    if (!in) {
        std::cerr << "Failed to open file";
        return 1;
    }

    int value;
    while (in >> value) { // reads until end-of-file or parse failure
        try{
            std::cout << value << "\n";
        } catch (...) {
            std::cerr << "Failed to parse value\n";
        }
    }
    in.close();

    // in >> value splits on whitespace so we have to read CSVs differently

    // Read a CSV file line by line
    std::ifstream in2("data.csv"); // reopen — in was already closed above
    std::string line;
    while (std::getline(in2,line)){ // read one line at a time
        std::stringstream ss(line); //treat the line as a stream
        std::string cell;
        while (std::getline(ss,cell,',')){ // split on commas
            try {
                double val = std::stod(cell); // convert string to double. std::stoi for int, std::stof for float, etc.
                std::cout << val << "\n";
            } catch (...) {} // skip cells that aren't numbers (e.g. "hello")
        }
    }

    return 0;

}