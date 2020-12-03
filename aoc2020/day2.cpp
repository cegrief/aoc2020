#include "day2.h"
#include <algorithm>>""

int day2::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}

int day2::partA(vector<string> input) {

	int good_pass = 0;

	for (string line : input) {
		int colon_index = line.find(':');
		int dash_index = line.find('-');

		int min = std::stoi(line.substr(0, dash_index));
		int max = std::stoi(line.substr(dash_index + 1, (colon_index - dash_index - 3)));
		char c = line[colon_index-1];
		
		int c_count = std::count(line.begin() + colon_index + 2, line.end(), c);

		if (!(c_count < min || c_count > max)){
			good_pass++;
		}
	}
	return good_pass;
}

int day2::partB(vector<string> input) {
	int good_pass = 0;

	for (string line : input) {
		int colon_index = line.find(':');
		int dash_index = line.find('-');

		int first = std::stoi(line.substr(0, dash_index)) - 1;
		int second = std::stoi(line.substr(dash_index + 1, (colon_index - dash_index - 3))) - 1;
		char c = line[colon_index - 1];
		string password = line.substr(colon_index + 2);

		bool first_match = password.at(first) == c;
		bool second_match = password.at(second) == c;
		if (first_match ^ second_match) {
			good_pass++;
		}
	}
	return good_pass;
}