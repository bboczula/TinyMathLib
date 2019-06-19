#include "pch.h"
#include "CppUnitTest.h"
#include "../TinyMathLib/TinyMathLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(GeneralVector2DTesting)
	{
	public:
		
		TEST_METHOD(TestVectorNegation1)
		{
			TinyMathLib::Vector2D<float> vector(4.0f, -5.0f);
			TinyMathLib::Vector2D<float> result = -vector;

			Assert::AreEqual(result.x, -4.0f);
			Assert::AreEqual(result.y, 5.0f);

		}
		TEST_METHOD(TestVectorNegation2)
		{
			TinyMathLib::Vector2D<float> vector(-4.0f, 5.0f);
			TinyMathLib::Vector2D<float> result = -vector;

			Assert::AreEqual(result.x, 4.0f);
			Assert::AreEqual(result.y, -5.0f);
		}
		TEST_METHOD(TestVectorNegation3)
		{
			TinyMathLib::Vector2D<float> vector(-1.0f, -1.0f);
			TinyMathLib::Vector2D<float> result = -vector;

			Assert::AreEqual(result.x, 1.0f);
			Assert::AreEqual(result.y, 1.0f);
		}
		TEST_METHOD(TestVectorNegation4)
		{
			TinyMathLib::Vector2D<float> vector(1.0f, 1.0f);
			TinyMathLib::Vector2D<float> result = -vector;

			Assert::AreEqual(result.x, -1.0f);
			Assert::AreEqual(result.y, -1.0f);
		}
		TEST_METHOD(TestVectorNegation5)
		{
			TinyMathLib::Vector2D<float> vector;
			TinyMathLib::Vector2D<float> result = -vector;

			Assert::AreEqual(result.x, 0.0f);
			Assert::AreEqual(result.y, 0.0f);
		}
	};
}
