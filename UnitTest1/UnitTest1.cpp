#include "pch.h"
#include "CppUnitTest.h"
#include "../Decimal.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Decimal a1(10, "12312"), a2(10, "32323"), a3(10);
			a3 = a1 + a2;
			Assert::AreEqual(a3[0], unsigned char('5'));
			Assert::AreEqual(a3[3], unsigned char('4'));
			Assert::AreEqual(a3[2], unsigned char('6'));
		}
	};
}
