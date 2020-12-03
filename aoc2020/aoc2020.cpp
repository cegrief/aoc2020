// aoc2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>
#include <sstream>

#include "day1.h";


using std::string;
using std::vector;

vector<string> getInput(int day)
{
    string inputPath = std::filesystem::current_path().generic_string() + "/../inputs/" + std::to_string(day) + ".txt";

    vector<string> output;
    string line;

    std::ifstream inFile(inputPath);

    while (getline(inFile, line))
        output.push_back(line);

    return output;
}

int executeFunction(int day, bool partB, vector<string> input) 
{
    typedef int (*FnPtr)(vector<string>, bool);
    std::map<int, FnPtr> fnMap;

    fnMap[1] = day1::run;

    auto start = std::chrono::high_resolution_clock::now();
    int result = fnMap[day](input, partB);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Completed in " << duration.count() << "μs" << std::endl;

    return result;
}


int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Please enter in a day and (optionally) true if it is a partB";
        return -1;
    }

    int day = std::stoi(argv[1]);

    bool partB = false;
    if (argc > 2) {
        std::istringstream(argv[2]) >> std::boolalpha >> partB;
    }

    std::cout << "Running " << day << (partB ? "B" : "A") << std::endl;


    vector<string> inp = getInput(day);

    int result = executeFunction(day, partB, inp);
    std::cout << "Result: " << result << std::endl;
}