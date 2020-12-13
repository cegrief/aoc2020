#include "day11.h"
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <iostream>
#include "utils.h"
#include <list>

long long day11::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}


int count_adjacent_seats(vector<string> input, int row, int col) {
	int count = 0;

	for (int i = row - 1; i < row + 2; i++) {
		for (int j = col - 1; j < col + 2; j++) {
			if ((i >= 0) && (i < input.size()) && (j >= 0) && (j < input[0].length())) {
				if (input[i][j] == '#' && !(i == row && j == col)) {
					count++;
				}
			}
		}
	}

	return count;
}

bool get_updated_seats(vector<string> &input) {

	vector<string> next{};
	bool did_change = false;

	for (int i = 0; i < input.size(); i++) {
		string row = "";
		for (int j = 0; j < input[0].size(); j++) {
			char curr = input[i][j];
			int neighborCount = count_adjacent_seats(input, i, j);

			if (curr == 'L' && neighborCount == 0) {
				row += '#';
				did_change = true;
			}

			else if (curr == '#' && neighborCount >= 4) {
				row += 'L';
				did_change = true;
			}

			else {
				row += curr;
			}
		}
		next.push_back(row);
	}

	input = next;
	return did_change;
}

long long day11::partA(vector<string> input) {

	vector<string> curr = input;

	bool did_change = true;
	int iter = 0;
	while (did_change) {
		did_change = get_updated_seats(curr);
		std::cout << iter++ << std::endl;
	}

	//count occupied
	int count = 0;
	for (auto s : curr) {
		count += std::count(s.begin(), s.end(), '#');
	}

	return count;
	
}

bool scan_direction_for_seat(vector<string> input, int row, int col, int rowdir, int coldir) {

	if (rowdir == 0 && coldir == 0) {
		return false;
	}
	int curr_row = row + rowdir;
	int curr_col = col + coldir;

	while (curr_row < input.size() && curr_row >= 0 && curr_col < input[0].length() && curr_col >= 0) {
		if (input[curr_row][curr_col] != '.') {
			if (input[curr_row][curr_col] == '#') {
				return true;
			}
			return false;
		}
		curr_row += rowdir;
		curr_col += coldir;
	}

	return false;
}

int count_los_seats(vector<string> input, int row, int col) {
	int count = 0;

	vector<int> rowdirs = { -1, 0, 1 };
	vector<int> coldirs = { -1, 0, 1 };
	
	for (auto rowdir : rowdirs) {
		for (auto coldir : coldirs) {
			if (scan_direction_for_seat(input, row, col, rowdir, coldir)) {
				count++;
			}
		}
	}


	return count;
}

bool get_updated_seatsB(vector<string>& input) {

	vector<string> next{};
	bool did_change = false;

	for (int i = 0; i < input.size(); i++) {
		string row = "";
		for (int j = 0; j < input[0].size(); j++) {
			char curr = input[i][j];
			int neighborCount = count_los_seats(input, i, j);

			if (curr == 'L' && neighborCount == 0) {
				row += '#';
				did_change = true;
			}

			else if (curr == '#' && neighborCount >= 5) {
				row += 'L';
				did_change = true;
			}

			else {
				row += curr;
			}
		}
		next.push_back(row);
	}

	input = next;
	return did_change;
}

long long day11::partB(vector<string> input) {
	vector<string> curr = input;

	bool did_change = true;
	int iter = 0;
	while (did_change) {
		did_change = get_updated_seatsB(curr);
		std::cout << iter++ << std::endl;
	}

	//count occupied
	int count = 0;
	for (auto s : curr) {
		count += std::count(s.begin(), s.end(), '#');
	}

	return count;
}
