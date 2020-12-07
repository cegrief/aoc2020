#include "day4.h"
#include <algorithm>
#include <map>
#include <regex>
#include <sstream>
#include <iostream>
#include <list>
#include <set>
#include "utils.h"

long long day4::run(vector<string> input, bool isPartB) {

	if (isPartB) {
		return partB(input);
	}
	else {
		return partA(input);
	}
}

bool isWhiteSpace(string input) {
	return input.find_first_not_of("\t\n ") == string::npos;
}

bool day4::isValid(string passport, vector<string> ignoreKeys) {

	std::list<string> includeKeys = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid" };
	for (string ignore : ignoreKeys) {
		includeKeys.remove(ignore);
	}


	std::map<string, string> passportMap{};

	for (string kvp : utils::splitString(passport, ' ')) {
		auto kvpSplit = utils::splitString(kvp, ':');
		passportMap[kvpSplit[0]] = kvpSplit[1];
	}

	for (string key : includeKeys) {
		if (passportMap.count(key) == 0) {
			return false;
		}
	}

	return true;
}

bool day4::isValidB(string passport, vector<string> ignoreKeys) {

	std::list<string> includeKeys = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };
	for (string ignore : ignoreKeys) {
		includeKeys.remove(ignore);
	}


	std::map<string, string> passportMap{};

	for (string kvp : utils::splitString(passport, ' ')) {
		auto kvpSplit = utils::splitString(kvp, ':');
		passportMap[kvpSplit[0]] = kvpSplit[1];
	}

	for (string key : includeKeys) {
		if (passportMap.count(key) == 0) {
			return false;
		}
	}

	//byr needs to be 4 digits, between 1920 and 2002
	if (passportMap["byr"].length() != 4 || stoi(passportMap["byr"]) < 1920 || stoi(passportMap["byr"]) > 2002) {
		return false;
	}
	//iyr needs to be 4 digits, between 2010 and 2020
	if (passportMap["iyr"].length() != 4 || stoi(passportMap["iyr"]) < 2010 || stoi(passportMap["iyr"]) > 2020) {
		return false;
	}
	//eyr between 2020 and 2030
	if (passportMap["eyr"].length() != 4 || stoi(passportMap["eyr"]) < 2020 || stoi(passportMap["eyr"]) > 2030) {
		return false;
	}

	//hgt number followed by cm or in
	string hgt = passportMap["hgt"];

	if (!std::regex_match(hgt, std::regex("^[0-9]+(?:cm|in)$"))) {
		return false;
	}
	int hgtVal = stoi(hgt.substr(0, hgt.length() - 2));
	string hgtUnit = hgt.substr(hgt.length() - 2);
	if (hgtUnit == "in") {
		if (hgtVal < 59 || hgtVal > 76) {
			return false;
		}
	}
	else if (hgtUnit == "cm") {
		if (hgtVal < 150 || hgtVal > 193) {
			return false;
		}
	}
	else {
		return false;
	}

	//hcl is a # followed by 6 characters 0-9 or a-f
	if (!std::regex_match(passportMap["hcl"], std::regex("^#(?:[0-9a-fA-F]{6})$"))) {
		return false;
	}


	//ecl must be in this set
	std::set<string> eyeColors  = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

	if (eyeColors.find(passportMap["ecl"]) == eyeColors.end()) {
		return false;
	}

	//pid must be a 9 digit number
	if (!std::regex_match(passportMap["pid"], std::regex("^(?:[0-9]{9})$"))) {
		return false;
	}

	return true;
}

long long day4::partA(vector<string> input) {
	vector<string> ignoreKeys = { "cid" };
	int line_num = 0;
	std::stringstream currPassport;
	int valid_count = 0;
	while (line_num < input.size()) {
		if (isWhiteSpace(input[line_num])) {
			if (isValid(currPassport.str(), ignoreKeys)) {
				valid_count++;
			}
			currPassport.str(string());
		}
		else {
			currPassport << input[line_num] << " ";
		}
		line_num++;
	}

	if (isValid(currPassport.str(), ignoreKeys)) {
		valid_count++;
	}

	return valid_count;
}

long long day4::partB(vector<string> input) {

	vector<string> ignoreKeys = { "cid" };
	int line_num = 0;
	std::stringstream currPassport;
	int valid_count = 0;
	while (line_num < input.size()) {
		if (isWhiteSpace(input[line_num])) {
			if (isValidB(currPassport.str(), ignoreKeys)) {
				valid_count++;
			}
			currPassport.str(string());
		}
		else {
			currPassport << input[line_num] << " ";
		}
		line_num++;
	}

	if (isValidB(currPassport.str(), ignoreKeys)) {
		valid_count++;
	}

	return valid_count;
}