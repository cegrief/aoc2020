#include "pch.h"
#include "CppUnitTest.h"
#include "../aoc2020/day1.h"
#include "../aoc2020/day1.cpp"
#include "../aoc2020/day2.h"
#include "../aoc2020/day2.cpp"
#include "../aoc2020/day3.h"
#include "../aoc2020/day3.cpp"
#include "../aoc2020/day4.h"
#include "../aoc2020/day4.cpp"
#include "../aoc2020/day5.h"
#include "../aoc2020/day5.cpp"
#include "../aoc2020/day6.cpp"
#include "../aoc2020/day6.h"
#include "../aoc2020/day7.cpp"
#include "../aoc2020/day7.h"
#include "../aoc2020/day8.cpp"
#include "../aoc2020/day8.h"
#include "../aoc2020//utils.h"
#include "../aoc2020//utils.cpp"
#include "../aoc2020/day9.cpp"
#include "../aoc2020/day9.h"
#include "../aoc2020/day10.cpp"
#include "../aoc2020/day10.h"
#include "../aoc2020/day11.cpp"
#include "../aoc2020/day11.h"
#include "../aoc2020/day12.cpp"
#include "../aoc2020/day12.h"
#include "../aoc2020/day13.cpp"
#include "../aoc2020/day13.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace aoc2020Tests
{
	TEST_CLASS(aoc2020Tests)
	{
	public:

		TEST_METHOD(Day1Test)
		{
			std::vector<string> input = { "1721", "979", "366", "299", "675", "1456" };
			Assert::AreEqual(514579ll, day1::run(input, false));
			Assert::AreEqual(241861950ll, day1::run(input, true));
		}

		TEST_METHOD(Day2Test)
		{
			std::vector<string> input = { "1-3 a: abcde", "1-3 b: cdefg", "2-9 c: ccccccccc" };
			Assert::AreEqual(2ll, day2::run(input, false));
			Assert::AreEqual(1ll, day2::run(input, true));
		}

		TEST_METHOD(Day3Test)
		{
			std::vector<string> input = { "..##.......", "#...#...#..", ".#....#..#.", "..#.#...#.#", ".#...##..#.", "..#.##.....", ".#.#.#....#", ".#........#", "#.##...#...", "#...##....#", ".#..#...#.#" };
			Assert::AreEqual(7ll, day3::run(input, false));
			Assert::AreEqual(336ll, day3::run(input, true));
		}

		TEST_METHOD(Day4Test)
		{
			std::vector<string> input = { "ecl:gry pid:860033327 eyr:2020 hcl:#fffffd", "byr:1937 iyr:2017 cid:147 hgt:183cm", "", "iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884", "hcl:#cfa07d byr:1929", " ", "hcl:#ae17e1 iyr:2013", "eyr:2024", "ecl:brn pid:760753108 byr:1931", "hgt:179cm", "    ", "hcl:#cfa07d eyr:2025 pid:166559648", "iyr:2011 ecl:brn hgt:59in" };
			Assert::AreEqual(2ll, day4::run(input, false));

			Assert::AreEqual(false, day4::isValidB("pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1919 hcl:#623a2f", vector<string>{})); //invalid byr
			Assert::AreEqual(false, day4::isValidB("pid:087499704 hgt:74in ecl:grn iyr:2021 eyr:2030 byr:1980 hcl:#623a2f", vector<string>{})); //invalid iyr
			Assert::AreEqual(false, day4::isValidB("pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:20400 byr:1980 hcl:#623a2f", vector<string>{})); //invalid eyr
			Assert::AreEqual(false, day4::isValidB("pid:087499704 hgt:740in ecl:grn iyr:2012 eyr:2030 byr:1980 hcl:#623a2f", vector<string>{})); //invalid hgt
			Assert::AreEqual(false, day4::isValidB("pid:087499704 hgt:74 ecl:grn iyr:2012 eyr:2030 byr:1980 hcl:#623a2f", vector<string>{})); //invalid hgt
			Assert::AreEqual(false, day4::isValidB("pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980 hcl:#623a2q", vector<string>{})); //invalid hcl
			Assert::AreEqual(false, day4::isValidB("pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980 hcl:623a2f", vector<string>{})); //invalid hcl
			Assert::AreEqual(false, day4::isValidB("pid:087499704 hgt:74in ecl:pur iyr:2012 eyr:2030 byr:1980 hcl:#623a2f", vector<string>{})); //invalid ecl
			Assert::AreEqual(false, day4::isValidB("pid:08749970004 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980 hcl:#623a2f", vector<string>{})); //invalid pid
			Assert::AreEqual(false, day4::isValidB("pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980", vector<string>{})); //missing entry
			Assert::AreEqual(true, day4::isValidB("pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980 hcl:#623a2f", vector<string>{}));
		}


		TEST_METHOD(Day5Test)
		{
			std::vector<string> input = { "FBFBBFFRLR", "BFFFBBFRRR", "FFFBBBFRRR", "BBFFBBFRLL" };
			Assert::AreEqual(820ll, day5::run(input, false));
			std::vector<string> input2 = { "FFFBFFFRRR", "FFFBFFFRLR", };
			Assert::AreEqual(70ll, day5::run(input2, true));
		}

		TEST_METHOD(Day6Test)
		{
			std::vector<string> input = { "abc", "", "a", "b", "c" , "", "ab", "ac", "", "a", "a","a","a", " ", "b" };
			Assert::AreEqual(11ll, day6::run(input, false));

			std::vector<string> input2 = { "fzmwqgcjylr" ,"goqewcrzfjm" ,"caqgpmrwz" };
			Assert::AreEqual(7ll, day6::run(input2, true));
		}

		TEST_METHOD(Day7Test)
		{
			std::vector<string> input = { "light red bags contain 1 bright white bag, 2 muted yellow bags.", "dark orange bags contain 3 bright white bags, 4 muted yellow bags.","bright white bags contain 1 shiny gold bag.", "muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.", "shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.", "dark olive bags contain 3 faded blue bags, 4 dotted black bags.", "vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.","faded blue bags contain no other bags.","dotted black bags contain no other bags." };
			Assert::AreEqual(4ll, day7::run(input, false));
			Assert::AreEqual(32ll, day7::run(input, true));
		}


		TEST_METHOD(Day8Test)
		{
			std::vector<string> input = { "nop +0",
"acc +1",
"jmp +4",
"acc +3",
"jmp -3",
"acc -99",
"acc +1",
"jmp -4",
"acc +6" };
			Assert::AreEqual(5ll, day8::run(input, false));
			Assert::AreEqual(8ll, day8::run(input, true));
		}


		TEST_METHOD(Day9Test)
		{
			std::vector<long long> input = { 35, 20, 15, 25, 47, 40, 62, 55, 65, 95,102,117,150,182,127,219,299,277,309,576 };
			Assert::AreEqual(127ll, day9::partA(input, 5));
			Assert::AreEqual(62ll, day9::partB(input, 5));
		}

		TEST_METHOD(Day10Test)
		{
			std::vector<long long> input = { 28,
33,
18,
42,
31,
14,
46,
20,
48,
47,
24,
23,
49,
45,
19,
38,
39,
11,
1 ,
32,
25,
35,
8 ,
17,
7 ,
9 ,
4 ,
2 ,
34,
10,
3 };
			Assert::AreEqual(220ll, day10::partA(input, 5));
			Assert::AreEqual(19208ll, day10::partB(input, 5));
		}

		TEST_METHOD(Day11Test)
		{
			std::vector<string> input = { "L.LL.LL.LL",
"LLLLLLL.LL",
"L.L.L..L..",
"LLLL.LL.LL",
"L.LL.LL.LL",
"L.LLLLL.LL",
"..L.L.....",
"LLLLLLLLLL",
"L.LLLLLL.L",
"L.LLLLL.LL" };
			Assert::AreEqual(37ll, day11::partA(input));
			Assert::AreEqual(26ll, day11::partB(input));
		}

		TEST_METHOD(Day12Test)
		{
			std::vector<string> input = { "F10", "N3", "F7", "L270", "F11" };
			Assert::AreEqual(25ll, day12::partA(input));
			Assert::AreEqual(286ll, day12::partB(input));
		}

		TEST_METHOD(Day13Test)
		{

			std::vector<string> input = { "x", "7, 13,x,x,59,x,31,19" };
			Assert::AreEqual(1068781ll, day13::partB(input));

			std::vector<string> input2 = { "x", "67,7,59,61" };
			Assert::AreEqual(754018ll, day13::partB(input2));

		}
	};
}
