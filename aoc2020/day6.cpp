#include "day6.h"
#include <algorithm>
#include <map>
#include <numeric>
#include <set>

long long day6::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}

bool isWhiteSpace2(string input) {
	return input.find_first_not_of("\t\n ") == string::npos;
}


int getUniqueYes(vector<string> rows) {

	std::set<char> yesQs{};

	for (string answers : rows) {
		for (char c : answers) {
			yesQs.insert(c);
		}
	}

	return yesQs.size();
}

int getEveryoneYes(vector<string> rows) {

	std::map<char, int> yesQs{};
	int members = rows.size();

	for (string answers : rows) {
		for (char c : answers) {
			if (yesQs.find(c) == yesQs.end()) {
				yesQs[c] = 1;
			}
			else {
				yesQs[c]++;
			}
		}
	}

	int count = 0;
	for (auto it = yesQs.begin(); it != yesQs.end(); ++it) {
		if (it->second == members) {
			count++;
		}
	}

	return count;
}

long long day6::partA(vector<string> input) {

	vector<string> currGroup{};
	vector<int> counts{};

	for (string line : input) {
		if (isWhiteSpace2(line)) {
			int count = getUniqueYes(currGroup);
			counts.push_back(count);
			currGroup = {};
		}
		else {
			currGroup.push_back(line);
		}
	}

	int count = getUniqueYes(currGroup);
	counts.push_back(count);

	return std::accumulate(counts.begin(), counts.end(), 0);
}


long long day6::partB(vector<string> input) {
	vector<string> currGroup{};
	vector<int> counts{};

	for (string line : input) {
		if (isWhiteSpace2(line)) {
			int count = getEveryoneYes(currGroup);
			counts.push_back(count);
			currGroup = {};
		}
		else {
			currGroup.push_back(line);
		}
	}

	int count = getEveryoneYes(currGroup);
	counts.push_back(count);

	return std::accumulate(counts.begin(), counts.end(), 0);
}