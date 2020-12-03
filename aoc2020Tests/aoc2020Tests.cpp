#include "pch.h"
#include "CppUnitTest.h"
#include "../aoc2020/day1.h"
#include "../aoc2020/day1.cpp"
#include "../aoc2020/day2.h"
#include "../aoc2020/day2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace aoc2020Tests
{
	TEST_CLASS(aoc2020Tests)
	{
	public:
		
		TEST_METHOD(Day1Test)
		{
			std::vector<string> input = { "1721", "979", "366", "299", "675", "1456" };
			Assert::AreEqual(514579, day1::run(input, false));
			Assert::AreEqual(241861950, day1::run(input, true));
		}

		TEST_METHOD(Day2Test)
		{
			std::vector<string> input = { "1-3 a: abcde", "1-3 b: cdefg", "2-9 c: ccccccccc" };
			Assert::AreEqual(2, day2::run(input, false));
			Assert::AreEqual(1, day2::run(input, true));
		}
	};
}
