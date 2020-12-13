#include "day12.h"
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <iostream>
#include "utils.h"
#include <list>

long long day12::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}

vector<int> NORTH = { 0, 1 };
vector<int> SOUTH = { 0, -1 };
vector<int> EAST = { 1, 0 };
vector<int> WEST = { -1, 0 };

vector<vector<int>> directions = { NORTH, EAST, SOUTH, WEST };

struct ShipPosition {
	vector<int> position{};
	int facing{};

	ShipPosition() {
		position = vector<int>{ 0,0 };
		facing = 90;
	}
};

void update_position(ShipPosition &pos, char direction, int value) {

	switch (direction) {
	case 'N':
		pos.position[1] += value;
		break;
	case 'S':
		pos.position[1] -= value;
		break;
	case 'E':
		pos.position[0] += value;
		break;
	case 'W':
		pos.position[0] -= value;
		break;
	case 'L':
		pos.facing = (pos.facing + (360 - value)) % 360;
		break;
	case 'R':
		pos.facing = (pos.facing + value) % 360;
		break;
	case 'F':
		int idx = pos.facing / 90;
		auto dir = directions[idx];

		pos.position[0] += dir[0] * value;
		pos.position[1] += dir[1] * value;
		break;
	}
	
}

long long day12::partA(vector<string> input) {

	ShipPosition pos;

	for (auto line : input) {
		char direction = line[0];
		int val = stoi(line.substr(1));

		update_position(pos, direction, val);
	}

	return std::abs(pos.position[0]) + std::abs(pos.position[1]);
}

void update_position_b(ShipPosition &pos, vector<int> &wayOffset, char direction, int value) {
	switch (direction) {
	case 'N':
		wayOffset[1] += value;
		break;
	case 'S':
		wayOffset[1] -= value;
		break;
	case 'E':
		wayOffset[0] += value;
		break;
	case 'W':
		wayOffset[0] -= value;
		break;
	case 'L':
	{
		int ccw = value % 360;
		while (ccw > 0) {
			int temp = wayOffset[0];
			wayOffset[0] = -wayOffset[1];
			wayOffset[1] = temp;
			ccw -= 90;
		}
		break;
	}
	case 'R':
	{
		int cw = value % 360;
		while (cw > 0) {
			int temp = wayOffset[0];
			wayOffset[0] = wayOffset[1];
			wayOffset[1] = -temp;
			cw -= 90;
		}
		break;
	}
	case 'F':
		pos.position[0] += value * wayOffset[0];
		pos.position[1] += value * wayOffset[1];
		break;
	}
}

long long day12::partB(vector<string> input) {
	ShipPosition pos;
	vector<int> wayOffset{ 10, 1 };

	for (auto line : input) {
		char direction = line[0];
		int val = stoi(line.substr(1));

		update_position_b(pos, wayOffset, direction, val);
	}

	return std::abs(pos.position[0]) + std::abs(pos.position[1]);
}
