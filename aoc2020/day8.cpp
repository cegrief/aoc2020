#include "day8.h"
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <iostream>
#include "utils.h"

long long day8::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}

long long day8::partA(vector<string> input) {

	int i = 0;
	std::set<int> visited{};
	int accumulator = 0;

	while(visited.find(i) == visited.end() && i >= 0 && i < input.size()) {
		visited.insert(i);
		string line = input[i];
		auto parts = utils::splitString(line, ' ');
		string instruction = parts[0];
		int val = stoi(parts[1].substr(1));
		if (parts[1][0] == '-') {
			val *= -1;
		}

		if (instruction == "nop") {
			i++;;
			continue;
		}
		else if (instruction == "acc") {
			i++;
			accumulator += val;
		}
		else if (instruction == "jmp") {
			i += val;
		}
	}

	return accumulator;

}


bool has_infinite_loop(vector<string> input) {
	int i = 0;
	std::set<int> visited{};

	while (i >= 0 && i < input.size()) {
		visited.insert(i);
		string line = input[i];
		auto parts = utils::splitString(line, ' ');
		string instruction = parts[0];
		int val = stoi(parts[1].substr(1));
		if (parts[1][0] == '-') {
			val *= -1;
		}

		if (instruction == "nop") {
			i++;;
		}
		else if (instruction == "acc") {
			i++;
		}
		else if (instruction == "jmp") {
			i += val;
		}

		if (visited.find(i) != visited.end()) {
			return true;
		}
	}

	return false;
}

long long day8::partB(vector<string> input) {

	vector<string> replacedInput{ input };
	for (int i = 0; i < input.size(); i++) {
		string line = input[i];
		auto parts = utils::splitString(line, ' ');
		string instruction = parts[0];

		if (instruction == "nop") {
			replacedInput[i] = "jmp " + parts[1];
		}
		else if (instruction == "jmp") {
			replacedInput[i] = "nop " + parts[1];
		}

		if (!has_infinite_loop(replacedInput)) {
			return partA(replacedInput);
		}
		else {
			replacedInput[i] = line;
		}
	}

	throw;
}
