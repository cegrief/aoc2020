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


std::map<string, vector<string>> parse_inputA(vector<string> input) {
	std::map<string, vector<string>> out{};

	for (auto line : input) {
		vector<string> items = utils::splitString(line, ' ');

		string srcColor = items[0] + items[1];
		int i = 0;
		while (i < items.size()) {
			if (is_number(items[i]) && i + 1 < items.size() && i + 2 < items.size()) {
				string destColor = items[i + 1] + items[i + 2];

				if (out.find(destColor) == out.end()) {
					out[destColor] = vector<string>{};
				}
				out[destColor].push_back(srcColor);
				i++;
			}
			else {
				i++;
			}
		}
	}
	return out;
}


void get_color_containers(string color, std::map<string, vector<string>> bags, std::set<string> &colors_sofar) {

	for (auto container : bags[color]) {
		// only visit this node if we haven't already
		if (colors_sofar.find(container) == colors_sofar.end()) {
			colors_sofar.insert(container);
			get_color_containers(container, bags, colors_sofar);
		}
	}
}

long long day7::partA(vector<string> input) {

	auto bags_contained_in = parse_inputA(input);

	// search down from gold to all of the things that contain it
	std::set<string> contains_gold{};
	get_color_containers("shinygold", bags_contained_in, contains_gold);
	return contains_gold.size();

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

std::map<string, vector<Edge>> parse_inputB(vector<string> input) {
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

long long day7::partB(vector<string> input) {
	//construct tree about input
	std::map<string, int> memo{};

	auto bags = parse_inputB(input);

	//starting with shinygold, count the number of bags needed
	return containsBagCount("shinygold", bags, memo) - 1;

}
