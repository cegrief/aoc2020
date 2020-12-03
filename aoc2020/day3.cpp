#include "day3.h"
#include <algorithm>

long long day3::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}

long long day3::partA(vector<string> input) {

	int row_hop = 1;
	int col_hop = 3;

	int max_row = input.size();
	int max_col = input[0].length();

	int row = 0;
	int col = 0;
	int tree_count = 0;

	while (row < max_row) {
		if (input[row][col] == '#') {
			tree_count++;
		}

		row += row_hop;
		col = (col + col_hop) % max_col;
	}

	return tree_count;
}

long long day3::partB(vector<string> input) {

	vector<int> col_hops = { 1,3,5,7,1 };
	vector<int> row_hops = { 1,1,1,1,2 };

	int max_row = input.size();
	int max_col = input[0].length();

	long long result = 1;

	for (int i = 0; i < row_hops.size(); i++) {

		int row_hop = row_hops[i];
		int col_hop = col_hops[i];
		int row = 0;
		int col = 0;
		int tree_count = 0;

		while (row < max_row) {
			if (input[row][col] == '#') {
				tree_count++;
			}

			row += row_hop;
			col = (col + col_hop) % max_col;
		}

		result *= tree_count;
	}

	return result;
}