#include "day1.h"
#include <iostream>;
#include <unordered_map>;
#include <algorithm>


int day1::run(vector<string> input, bool isPartB) {

	std::vector<int> input_int;
	std::transform(input.begin(), input.end(), std::back_inserter(input_int), [](const string& str) { return std::stoi(str); });

	if (isPartB) {
		return partB(input_int);
	}
	else {
		return partA(input_int);
	}
}

int day1::partA(vector<int> input) {
	
	bool numMap[2020] {};

	for (int val : input) {

		if (numMap[2020 - val]) {
			return val * (2020 - val);
		}
		else {
			numMap[val] = true;
		}
	}
	
	return -1;
}

int day1::partB(vector<int> input) {

	bool numMap[2020]{};

	for (int i = 0; i < input.size(); i++) {
		int val_i = input[i];
		for (int j = i + 1; j < input.size(); j++) {
			int val_j = input[j];
			if ((2020-val_i-val_j > 0) && (numMap[2020 - val_i - val_j])) {
				return val_i * val_j * (2020 - val_i - val_j);
			}
		}
		numMap[val_i] = true;
	}

	return -1;
}
