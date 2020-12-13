// aoc2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>
#include <sstream>

#include "day1.h";
#include "day2.h";
#include "day3.h";
#include "day4.h";
#include "day5.h";
#include "day6.h";
#include "day7.h";
#include "day8.h";
#include "day9.h";
#include "day10.h";
#include "day11.h";
#include "day12.h";
#include "day13.h";

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

long long executeFunction(int day, bool partB, vector<string> input) 
{
    typedef long long (*FnPtr)(vector<string>, bool);
    std::map<int, FnPtr> fnMap;

    fnMap[1] = day1::run;
    fnMap[2] = day2::run;
    fnMap[3] = day3::run;
    fnMap[4] = day4::run;
    fnMap[5] = day5::run;
    fnMap[6] = day6::run;
    fnMap[7] = day7::run;
    fnMap[8] = day8::run;
    fnMap[9] = day9::run;
    fnMap[10] = day10::run;
    fnMap[11] = day11::run;
    fnMap[12] = day12::run;
    fnMap[13] = day13::run;

    auto start = std::chrono::high_resolution_clock::now();
    long long result = fnMap[day](input, partB);
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

    long long result = executeFunction(day, partB, inp);
    std::cout << "Result: " << result << std::endl;
}