#include "day9.h"
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <iostream>
#include "utils.h"
#include <list>

long long day9::run(vector<string> input, bool isPartB) {
	vector<long long> input_int{};
	std::transform(input.begin(), input.end(), std::back_inserter(input_int), [](const string& str) { return std::stoll(str); });

	if (isPartB) {
		return partB(input_int, 25);
	}
	else {
		return partA(input_int, 25);
	}
}

bool is_valid_value(std::map<long long, int> preamble, long long val) {
	for (auto kvp : preamble) {
		if (preamble[kvp.first] > 0) {
			int diff = val - kvp.first;

			if (preamble.find(diff) != preamble.end() && preamble[diff] > 0) {
				return true;
			}
		}
	}
	return false;
}

long long get_first_invalid(vector<long long> input, int preamble_len) {
	std::map<long long , int> preamble{ };

	for (int i = 0; i < input.size(); i++) {
		if (i < preamble_len) {
			if (preamble.find(input[i]) == preamble.end()) {
				preamble[input[i]] = 0;
			}
			preamble[input[i]]++;
		}
		else if (is_valid_value(preamble, input[i])) {
			if (preamble.find(input[i]) == preamble.end()) {
				preamble[input[i]] = 0;
			}
			preamble[input[i]]++;
			preamble[input[i - preamble_len]]--;
		}
		else {
			return input[i];
		}
	}
}

long long day9::partA(vector<long long> input, int preamble_len) {

	return get_first_invalid(input, preamble_len);
}


vector<long long> find_target_sum(vector<long long> input, int target) {
	int start = 0;
	int currSum = input[0];

	for (int i = 1; i <= input.size(); i++) {
		while (currSum > target && start < i - 1) {
			currSum -= input[start];
			start++;
		}

		if (currSum == target) {
			vector<long long> subVector(input.begin() + start, input.begin() + i);
			return subVector;
		}

		currSum += input[i];
	}

	throw;
}

long long day9::partB(vector<long long> input, int preamble_len) {
	long long target = get_first_invalid(input, preamble_len);

	auto subarray = find_target_sum(input, target);
	return *std::min_element(subarray.begin(), subarray.end()) + *std::max_element(subarray.begin(), subarray.end());
}
