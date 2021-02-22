#include "pch.h"
#include "CppUnitTest.h"

#include "../Calculator/Calculator.h"
#include "../Calculator/Calculator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_for_lab17
{
	TEST_CLASS(Test_for_lab17)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int a = 3, b = 10;
			int res = 30;

			Assert::AreEqual(multiply(a, b), res);
		}
	};
}
