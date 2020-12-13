#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class day9
{
public:
	static long long run(vector<string> input, bool partB);
	static long long partA(vector<long long> input, int premable_len);
	static long long partB(vector<long long> input, int preamble_len);
};

