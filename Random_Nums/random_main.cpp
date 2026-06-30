#include <random>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

std::vector<int> generateHistogram(const std::vector<double>& data, double binWidth, int numBins) {

    std::vector<int> histogram(numBins, 0);
    for (double value : data) {
        int binIndex = static_cast<int>(value / binWidth);   // range starts at 0
        if (binIndex >= numBins) {
            binIndex = numBins - 1;   // clamp outliers into last bin
        }
        // value is always >= 0 for exponential, so no negative-index check needed
        histogram[binIndex]++;
    }
    return histogram;
}

std::vector<double> normalizeHistogram(const std::vector<int>& histogram, int numSamples, double binWidth) {

    // Convert raw counts into a probability density (comparable to λe^(−λx))

    std::vector<double> density(histogram.size());
    for (std::size_t i = 0; i < histogram.size(); ++i) {
        density[i] = static_cast<double>(histogram[i]) / (numSamples * binWidth);
    }
    return density;
}

void saveHistogramToCSV(const std::vector<int>& histogram, const std::string& filename, double binWidth) {

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open file for writing: " << filename << "\n";
        return;
    }

    for (size_t i = 0; i < histogram.size(); ++i) {
        outFile << i * binWidth << "," << histogram[i] << "\n";
    }
}

void saveDensityToCSV(const std::vector<double>& density, const std::string& filename, double binWidth) {
    
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open file for writing: " << filename << "\n";
        return;
    }
    for (std::size_t i = 0; i < density.size(); ++i) {
        outFile << i * binWidth << "," << density[i] << "\n";
    }
}

int main(){

    /*
    std::mt19937 engine(42); // 42 is a seed for the random number generator. 
    // Produces raw random bits
    
    
    std::random_device rd;
    std::mt19937 engine(rd()); // Use a random seed from the random device for better randomness in production code.
 

    mt19937 = "Mersenne Twister, 32-bit, period 2¹⁹⁹³⁷−1." 
    It's the standard general-purpose PRNG — long period, good statistical quality, fast.
    Takes the raw bits from the engine and transforms them into a distribution.

    std::uniform_real_distribution<double> uniform(0.0,1.0); // uniform distribution in the range [0.0, 1.0).

    double lambda = 2.0; // rate parameter for the exponential distribution
    std::exponential_distribution <double> exponential(lambda); // exponential distribution with lambda (rate parameter)

    Taking the example of neutron transport, the exponential distribution is used to 
    model the distance a neutron travels before interacting with a material. 
    The rate parameter (lambda), the macroscopic cross-section, is related to 
    the mean free path of the neutron in the material via 1/lambda.
    This means that for a lambda of 2.0 (1/length), the mean free 
    path is 0.5 length units.

    A higher lambda means a shorter mean free path, indicating that 
    interactions are more likely to occur over shorter distances.

    The porbability that a neutron will travel a distance x without interacting is given 
    by the exponential distribution's probability density function (PDF):
    p(x)=λe^(−λx)
    

    double freePath = exponential(engine); // Generate a random free path length based on the exponential distribution

    Another way of sampling this:

    double u = uniform(engine);       // u in (0,1)
    double freePath = -std::log(u) / lambda;

    We feed uniform randoms through the inverse of the 
    CDF of the exponential distribution to get samples from the exponential distribution.

    Caveat: cannot include 0 in the uniform distribution because log(0) is undefined.
    */

    double lambda = 2.0;
    int numSamples = 10000; // Number of free path lengths to generate

    std::mt19937 engine(42);
    std::exponential_distribution <double> exponential(lambda);

    std::vector<double> freePaths; // Vector to store the generated free path lengths
    freePaths.reserve(numSamples); // Reserve space for the specified number of free path lengths to avoid multiple reallocations

    for(int i = 0; i < numSamples; i++){
        freePaths.push_back(exponential(engine)); // Store the generated free path length in the vector
    }

    int numBins = 100; // Define the number of bins for the histogram
    double binWidth = 0.05; // Define the width of each bin in the histogram

    std::vector<int> histogram = generateHistogram(freePaths, binWidth, numBins); // Create a histogram with the specified number of bins and bin width
    std::vector<double> normalizedHistogram = normalizeHistogram(histogram, numSamples, binWidth); // Normalize the histogram

    saveHistogramToCSV(histogram, "histogram.csv", binWidth); // Save the histogram to a CSV file with the calculated bin width
    saveDensityToCSV(normalizedHistogram, "density.csv", binWidth);

}