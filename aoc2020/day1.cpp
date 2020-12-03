#include "day1.h"
#include <iostream>;
#include <unordered_map>;


int day1::run(vector<string> input, bool isPartB) {
	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}

int day1::partA(vector<string> input) {
	
	bool numMap[2020] {};

	for (string item : input) {
		int val = std::stoi(item);
		
		if (numMap[2020 - val]) {
			return val * (2020 - val);
		}
		else {
			numMap[val] = true;
		}

	}
}

int day1::partB(vector<string> input) {
	return 2;
}
