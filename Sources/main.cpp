#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../Headers/text.h"

int main() {
    std::ifstream istream("Resources/input.txt");
    std::string inputData;
    std::ostringstream sstream;
    sstream << istream.rdbuf();
    inputData = sstream.str();
    std::cout << "Specify how many cycles you want algorithm to proceed on the given text: ";
    int n;
    std::cin >> n;
    std::cout << "Input text: \n" << inputData << std::endl;
    TextDistortion distortion(inputData);
    std::string outputData = distortion(n);
    std::cout << "Result(" << n << " cycles): \n" << outputData << std::endl;
    std::cout << "Changed Text written to Resources/output.txt";
    istream.close();
    std::ofstream ostream("Resources/output.txt");
    ostream << outputData;
    ostream.close();
}