#include "day7.h"
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <iostream>
#include "utils.h"

long long day7::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}

struct Edge {
	string src, dest;
	int count;

	Edge(string s, string d, int c) {
		src = s;
		dest = d;
		count = c;
	}
};



bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool can_contain_gold(string bag, std::map<string, vector<Edge>> bags, std::map<string, bool> &memo) {

	if (memo.find(bag) != memo.end() && memo[bag]) {
		return true;
	}

	for (auto edge : bags[bag]) {
		if (edge.dest == "shinygold") {
			memo[bag] = true;
			return true;
		}
		if (memo.find(edge.dest) != memo.end() && memo[edge.dest]) {
			memo[bag] = true;
			return true;
		}
	}

	for (auto edge : bags[bag]){
		if (can_contain_gold(edge.dest, bags, memo)) {
			memo[bag] = true;
			return true;
		}
	}

	memo[bag] = false;
	return false;
}

std::map<string, vector<Edge>> parse_input(vector<string> input) {
	std::map<string, vector<Edge>> bags{};

	for (auto line : input) {
		vector<string> items = utils::splitString(line, ' ');

		string srcColor = items[0] + items[1];
		vector<Edge> edges{};
		int i = 0;
		while (i < items.size()) {
			if (is_number(items[i]) && i + 1 < items.size() && i + 2 < items.size()) {
				int count = stoi(items[i]);
				string destColor = items[i + 1] + items[i + 2];
				Edge e = Edge(srcColor, destColor, count);
				edges.push_back(e);
				i++;
			}
			else {
				i++;
			}
		}

		bags[srcColor] = edges;
	}

	return bags;

}

long long day7::partA(vector<string> input) {
	
	//construct tree about input
	std::map<string, bool> memo{};

	auto bags = parse_input(input);
	// foreach color check if it can contain gold
	int count = 0;
	for (auto kvp : bags) {
		if (can_contain_gold(kvp.first, bags, memo)) {
			count++;
		}
	}

	return count;

}

int containsBagCount(string bag, std::map<string, vector<Edge>> bags, std::map<string, int>& memo) {

	if (memo.find(bag) != memo.end()) {
		return memo[bag];
	}

	int count = 1;
	for (auto edge : bags[bag]) {
		if (memo.find(edge.dest) != memo.end()) {
			count += edge.count * memo[edge.dest];
		}
		else {
			int subCount = containsBagCount(edge.dest, bags, memo);
			memo[edge.dest] = subCount;
			count += edge.count * subCount;
		}
	}

	return count;
}

long long day7::partB(vector<string> input) {
	//construct tree about input
	std::map<string, int> memo{};

	auto bags = parse_input(input);

	//starting with shinygold, count the number of bags needed
	return containsBagCount("shinygold", bags, memo) - 1;

}
