#include "day10.h"
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <iostream>
#include "utils.h"
#include <list>

long long day10::run(vector<string> input, bool isPartB) {
	vector<long long> input_int{};
	std::transform(input.begin(), input.end(), std::back_inserter(input_int), [](const string& str) { return std::stoll(str); });

	if (isPartB) {
		return partB(input_int, 25);
	}
	else {
		return partA(input_int, 25);
	}
}

long long day10::partA(vector<long long> input, int preamble_len) {

	input.push_back(0); // add in the outlet
	std::sort(input.begin(), input.end());
	int diffs1 = 0;
	int diffs3 = 1; //the final built in adapter

	for (int i = 0; i < input.size() - 1; i++) {
		if (input[i + 1] - input[i] == 1) {
			diffs1++;
		}
		else if (input[i + 1] - input[i] == 3) {
			diffs3++;
		}
	}

	return diffs1 * diffs3;
}



long long count_valid_connections(vector<long long> input, int target, int currIndex, std::map<int, long long> &memo) {
	if (memo.find(input[currIndex]) != memo.end()) {
		return memo[input[currIndex]];
	}
	
	long long count = 0;
	int next = currIndex + 1;
	while (next < input.size() && input[next] - input[currIndex] <= 3) {
		count += count_valid_connections(input, target, next, memo);
		next++;
	}

	memo[input[currIndex]] = count;
	return count;
}

long long day10::partB(vector<long long> input, int preamble_len) {
	input.push_back(0); // add in the outlet
	std::sort(input.begin(), input.end());

	int target = input[input.size() - 1] + 3;
	input.push_back(target);

	std::map<int, long long> count_from_val{};
	count_from_val[input[input.size()-1]] = 1;

	return count_valid_connections(input, target, 0, count_from_val);

	
}
