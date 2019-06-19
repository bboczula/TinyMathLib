#include "pch.h"
#include "CppUnitTest.h"
#include "../TinyMathLib/TinyMathLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(GeneralVector2DTesting)
	{
	public:
		TEST_METHOD(TestInitialization1)
		{
			TinyMathLib::Vector2D<float> vector;

			Assert::AreEqual(vector.x, 0.0f);
			Assert::AreEqual(vector.y, 0.0f);
		}
		TEST_METHOD(TestInitialization2)
		{
			TinyMathLib::Vector2D<float> vector(3.141592f, 6.283184f);

			Assert::AreEqual(vector.x, 3.141592f);
			Assert::AreEqual(vector.y, 6.283184f);
		}
		TEST_METHOD(TestInitialization3)
		{
			TinyMathLib::Vector2D<float> vector = { 3.141592f, 6.283184f };

			Assert::AreEqual(vector.x, 3.141592f);
			Assert::AreEqual(vector.y, 6.283184f);
		}
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
		TEST_METHOD(TestVectorMultiplicationByScalar1)
		{
			TinyMathLib::Vector2D<float> vector;
			TinyMathLib::Vector2D<float> result = vector * 2;

			Assert::AreEqual(result.x, 0.0f);
			Assert::AreEqual(result.y, 0.0f);
		}
		TEST_METHOD(TestVectorMultiplicationByScalar2)
		{
			TinyMathLib::Vector2D<float> vector(3.14f, 3.14f);
			TinyMathLib::Vector2D<float> result = vector * 2;

			Assert::AreEqual(result.x, 6.28f);
			Assert::AreEqual(result.y, 6.28f);
		}
		TEST_METHOD(TestVectorMultiplicationByScalar3)
		{
			TinyMathLib::Vector2D<float> vector(1.0f, 1.5f);
			TinyMathLib::Vector2D<float> result = vector * 2;

			Assert::AreEqual(result.x, 2.0f);
			Assert::AreEqual(result.y, 3.0f);
		}
		TEST_METHOD(TestVectorMultiplicationByScalar4)
		{
			TinyMathLib::Vector2D<float> vector(100.0f, 50.0f);
			TinyMathLib::Vector2D<float> result = vector * 0.5f;

			Assert::AreEqual(result.x, 50.0f);
			Assert::AreEqual(result.y, 25.0f);
		}
	};
}
