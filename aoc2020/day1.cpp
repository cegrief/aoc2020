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
	
	return -1;
}

int day1::partB(vector<string> input) {

	bool numMap[2020]{};

	for (int i = 0; i < input.size(); i++) {
		int val_i = std::stoi(input[i]);
		for (int j = i + 1; j < input.size(); j++) {
			int val_j = std::stoi(input[j]);
			if ((2020-val_i-val_j > 0) && (numMap[2020 - val_i - val_j])) {
				return val_i * val_j * (2020 - val_i - val_j);
			}
		}
		numMap[val_i] = true;
	}

	return -1;
}
