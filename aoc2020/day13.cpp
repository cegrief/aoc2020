#include "day13.h"
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <iostream>
#include "utils.h"
#include <list>
#include <numeric>
#include <iostream>
#include <numeric>
#include <vector>
#include <execution>

long long day13::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}


long long day13::partA(vector<string> input) {

	int currTime = stoi(input[0]);

	int minDepTime = INT32_MAX;
	int minBusId = 0;
	for (auto id : utils::splitString(input[1], ',')) {
		if (id == "x") {
			continue;
		}

		int busid = stoi(id);
		int depTime = 0;
		while (currTime > depTime) {
			depTime += busid;
		}

		if (depTime < minDepTime) {
			minDepTime = depTime;
			minBusId = busid;
		}
	}

	return minBusId * (minDepTime - currTime);

}

bool satisfies_conditions(int val, vector<int> nums, vector<int> rems) {
	for (int i = 0; i < nums.size(); i++) {
		if (val % nums[i] != rems[i]) {
			return false;
		}
	}

	return true;
}

long long find_min_time_bruteforce(vector<int> nums, vector<int> rems) {
	int res = 1;

	while (true) {
		if (satisfies_conditions(res, nums, rems)) {
			return res;
		}
		res++;
	}
}

long long lcm(vector<int> nums) {

	long long ans = 1;
	for (auto el : nums) {
		ans = std::lcm(ans, el);
	}

	return ans;
}

long long find_min_time_lcm(vector<int> nums, vector<int> rems) {
	long long res = 1;
	long long step = 1;
	vector<int> lcmNums{};

	for (int i = 0; i < nums.size(); i++) {

		while (res % nums[i] != rems[i]) {
			res += step;
		}

		lcmNums.push_back(nums[i]);
		step = lcm(lcmNums);
	}

	return res;
}

long long day13::partB(vector<string> input) {
	
	long long timestamp = 1;
	long long step = 1;
	auto idList = utils::splitString(input[1], ',');

	vector<int> numbers{};
	vector<int> remainders{};

	for (int i =0; i<idList.size(); i++) {
		if (idList[i] == "x") {
			continue;
		}
		int value = stoi(idList[i]);
		numbers.push_back(value);
		if (i == 0) {
			remainders.push_back(i);
		}
		else {
			remainders.push_back(value - (i % value));
		}
	}

	long long ret = find_min_time_lcm(numbers, remainders);
	return ret;
}
