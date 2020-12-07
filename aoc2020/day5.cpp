#include "day5.h"
#include <algorithm>

long long day5::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}

int getRow(string pass) {

	int lowerbound = 0;
	int upperbound = 127;
	for (int i = 0; i < 7; i++) {
		int range_hop = ceil((upperbound - lowerbound) / 2.0);
		if (pass[i] == 'F') {
			upperbound -= range_hop;
		}
		else if (pass[i] == 'B') {
			lowerbound += range_hop;
		}
		else {
			throw;
		}
	}
	if (upperbound != lowerbound) {
		throw;
	}

	return lowerbound;
}

int getCol(string pass) {
	int lowerbound = 0;
	int upperbound = 7;
	for (int i = 7; i < 10; i++) {
		int range_hop = ceil((upperbound - lowerbound) / 2.0);
		if (pass[i] == 'L') {
			upperbound -= range_hop;
		}
		else if (pass[i] == 'R') {
			lowerbound += range_hop;
		}
		else {
			throw;
		}
	}
	if (upperbound != lowerbound) {
		throw;
	}

	return lowerbound;
}

int getId(int row, int col) {
	return (row * 8) + col;
}

long long day5::partA(vector<string> input) {

	int maxId = -1;

	for (string pass : input) {
		int row = getRow(pass);
		int col = getCol(pass);

		int id = getId(row, col);

		maxId = std::max(maxId, id);
	}

	return maxId;
}


int find_missing(vector<int> arr) {

	int prev = arr[0] - 1;
	for (int el : arr) {
		if (el != prev + 1) {
			return prev + 1;
		}
		prev = el;
	}
}

long long day5::partB(vector<string> input) {

	vector<int> ids{};

	for (string pass : input) {
		int row = getRow(pass);
		int col = getCol(pass);

		int id = getId(row, col);

		ids.push_back(id);
	}
	
	std::sort(ids.begin(), ids.end());

	return find_missing(ids);
}