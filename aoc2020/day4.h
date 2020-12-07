#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class day4
{
public:
	static long long run(vector<string> input, bool partB);
	static bool isValid(string passport, vector<string> ignoreKeys);
	static bool isValidB(string passport, vector<string> ignoreKeys);
	static long long partA(vector<string> input);
	static long long partB(vector<string> input);
};