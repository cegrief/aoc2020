#include "pch.h"
#include "CppUnitTest.h"
#include "../aoc2020/day1.h"
#include "../aoc2020/day1.cpp"

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
	};
}
