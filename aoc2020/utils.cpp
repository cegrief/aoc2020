#include "utils.h"

#include <sstream>;

vector<string> utils::splitString(string s, char delimiter) {
	std::istringstream ss(s);
	string segment;
	vector<string> out;
	while (std::getline(ss, segment, delimiter)) {
		out.push_back(segment);
	}

	return out;
}