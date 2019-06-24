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
		TEST_METHOD(TestVectorMultiplicationByVector1)
		{
			TinyMathLib::Vector2D<float> vectorA(100.0f, 50.0f);
			TinyMathLib::Vector2D<float> vectorB(2.0f, 0.5f);
			TinyMathLib::Vector2D<float> result = vectorA * vectorB;

			Assert::AreEqual(result.x, 200.0f);
			Assert::AreEqual(result.y, 25.0f);
		}
		TEST_METHOD(TestVectorMultiplicationByVector2)
		{
			TinyMathLib::Vector2D<float> vectorA(100.0f, 50.0f);
			TinyMathLib::Vector2D<float> vectorB;
			TinyMathLib::Vector2D<float> result = vectorA * vectorB;

			Assert::AreEqual(result.x, 0.0f);
			Assert::AreEqual(result.y, 0.0f);
		}
		TEST_METHOD(TestVectorDivisionByScalar1)
		{
			TinyMathLib::Vector2D<float> vector(100.0f, 50.0f);
			TinyMathLib::Vector2D<float> result = vector / 2.0f;

			Assert::AreEqual(result.x, 50.0f);
			Assert::AreEqual(result.y, 25.0f);
		}
		TEST_METHOD(TestVectorDivisionByScalar2)
		{
			TinyMathLib::Vector2D<float> vector(100.0f, 50.0f);
			TinyMathLib::Vector2D<float> result = vector / 1.0f;

			Assert::AreEqual(result.x, 100.0f);
			Assert::AreEqual(result.y, 50.0f);
		}
		TEST_METHOD(TestVectorDivisionByScalar3)
		{
			TinyMathLib::Vector2D<float> vectorA(100.0f, 50.0f);
			TinyMathLib::Vector2D<float> resultA = vectorA / 2.0f;

			TinyMathLib::Vector2D<float> vectorB(100.0f, 50.0f);
			TinyMathLib::Vector2D<float> resultB = vectorA * 0.5f;

			Assert::AreEqual(resultA.x, resultB.x);
			Assert::AreEqual(resultA.y, resultB.y);
		}
		TEST_METHOD(TestVectorDivisionByVector1)
		{
			TinyMathLib::Vector2D<float> vectorA(100.0f, 90.0f);
			TinyMathLib::Vector2D<float> vectorB(2.0f, 3.0f);
			TinyMathLib::Vector2D<float> result = vectorA / vectorB;

			Assert::AreEqual(result.x, 50.0f);
			Assert::AreEqual(result.y, 30.0f);
		}
		TEST_METHOD(TestVectorAddition1)
		{
			TinyMathLib::Vector2D<float> vectorA(100.0f, 90.0f);
			TinyMathLib::Vector2D<float> vectorB(2.0f, 3.0f);
			TinyMathLib::Vector2D<float> result = vectorA + vectorB;

			Assert::AreEqual(result.x, 102.0f);
			Assert::AreEqual(result.y, 93.0f);
		}
		TEST_METHOD(TestVectorAddition2)
		{
			TinyMathLib::Vector2D<float> vectorA(100.0f, 90.0f);
			TinyMathLib::Vector2D<float> vectorB(2.0f, 3.0f);
			TinyMathLib::Vector2D<float> resultA = vectorA + vectorB;
			TinyMathLib::Vector2D<float> resultB = vectorA + vectorB;

			Assert::AreEqual(resultA.x, resultB.x);
			Assert::AreEqual(resultA.y, resultB.y);
		}
		TEST_METHOD(TestVectorSubstraction1)
		{
			TinyMathLib::Vector2D<float> vectorA(100.0f, 90.0f);
			TinyMathLib::Vector2D<float> vectorB(2.0f, 3.0f);
			TinyMathLib::Vector2D<float> result = vectorA - vectorB;

			Assert::AreEqual(result.x, 98.0f);
			Assert::AreEqual(result.y, 87.0f);
		}
	};

	TEST_CLASS(GeneralMatrix2x2DTesting)
	{
	public:
		TEST_METHOD(TestInitialization1)
		{
			TinyMathLib::Matrix2x2<float> matrix;

			Assert::AreEqual(matrix.m11, 0.0f);
			Assert::AreEqual(matrix.m12, 0.0f);
			Assert::AreEqual(matrix.m21, 0.0f);
			Assert::AreEqual(matrix.m22, 0.0f);
		}
		TEST_METHOD(TestInitialization2)
		{
			TinyMathLib::Matrix2x2<float> matrix(1.0f, 2.0f, 3.0f, 4.0f);

			Assert::AreEqual(matrix.m11, 1.0f);
			Assert::AreEqual(matrix.m12, 2.0f);
			Assert::AreEqual(matrix.m21, 3.0f);
			Assert::AreEqual(matrix.m22, 4.0f);
		}
		TEST_METHOD(TestMatrixTransposition1)
		{
			TinyMathLib::Matrix2x2<float> matrixA(1.0f, 2.0f, 3.0f, 4.0f);
			TinyMathLib::Matrix2x2<float> matrixB = matrixA.transpose();

			Assert::AreEqual(matrixB.m11, 1.0f);
			Assert::AreEqual(matrixB.m12, 3.0f);
			Assert::AreEqual(matrixB.m21, 2.0f);
			Assert::AreEqual(matrixB.m22, 4.0f);
		}
		TEST_METHOD(TestMatrixTransposition2)
		{
			TinyMathLib::Matrix2x2<float> matrixA(1.0f, 2.0f, 3.0f, 4.0f);
			TinyMathLib::Matrix2x2<float> matrixB = matrixA.transpose();
			TinyMathLib::Matrix2x2<float> matrixC = matrixB.transpose();

			Assert::AreEqual(matrixC.m11, matrixA.m11);
			Assert::AreEqual(matrixC.m12, matrixA.m12);
			Assert::AreEqual(matrixC.m21, matrixA.m21);
			Assert::AreEqual(matrixC.m22, matrixA.m22);
		}
		TEST_METHOD(TestMatrixTransposition3)
		{
			TinyMathLib::Matrix2x2<float> matrixA(1.0f, 0.0f, 0.0f, 4.0f);
			TinyMathLib::Matrix2x2<float> matrixB = matrixA.transpose();

			Assert::AreEqual(matrixB.m11, matrixA.m11);
			Assert::AreEqual(matrixB.m12, matrixA.m12);
			Assert::AreEqual(matrixB.m21, matrixA.m21);
			Assert::AreEqual(matrixB.m22, matrixA.m22);
		}
		TEST_METHOD(TestMatrixMultiplicatoinByScalar1)
		{
			TinyMathLib::Matrix2x2<float> matrixA(1.2f, 3.4f, 4.5f, 6.7f);
			TinyMathLib::Matrix2x2<float> matrixB = matrixA * 2.0f;

			Assert::AreEqual(matrixB.m11, 2.4f);
			Assert::AreEqual(matrixB.m12, 6.8f);
			Assert::AreEqual(matrixB.m21, 9.0f);
			Assert::AreEqual(matrixB.m22, 13.4f);
		}
		TEST_METHOD(TestMatrixMultiplicationByMatrix1)
		{
			TinyMathLib::Matrix2x2<float> M1(-3.0f, 0.0f, 5.0f, 0.5f);
			TinyMathLib::Matrix2x2<float> M2(-7.0f, 2.0f, 4.0f, 6.0f);
			TinyMathLib::Matrix2x2<float> M3 = M1 * M2;

			Assert::AreEqual(M3.m11, 21.0f);
			Assert::AreEqual(M3.m12, -6.0f);
			Assert::AreEqual(M3.m21, -33.0f);
			Assert::AreEqual(M3.m22, 13.0f);
		}
		TEST_METHOD(TestMatrixMultiplicationByIdentity1)
		{
			TinyMathLib::Matrix2x2<float> M1(-3.0f, 0.0f, 5.0f, 0.5f);
			TinyMathLib::Matrix2x2<float> M2 = TinyMathLib::MakeIdentityMatrix2x2<float>();
			TinyMathLib::Matrix2x2<float> M3 = M1 * M2;

			Assert::AreEqual(M3.m11, M1.m11);
			Assert::AreEqual(M3.m12, M1.m12);
			Assert::AreEqual(M3.m21, M1.m21);
			Assert::AreEqual(M3.m22, M1.m22);
		}
	};

	TEST_CLASS(GeneralMatrix3x3DTesting)
	{
	public:
		TEST_METHOD(TestInitialization1)
		{
			TinyMathLib::Matrix3x3<float> matrix;

			Assert::AreEqual(matrix.m11, 0.0f);
			Assert::AreEqual(matrix.m12, 0.0f);
			Assert::AreEqual(matrix.m13, 0.0f);
			Assert::AreEqual(matrix.m21, 0.0f);
			Assert::AreEqual(matrix.m22, 0.0f);
			Assert::AreEqual(matrix.m23, 0.0f);
			Assert::AreEqual(matrix.m31, 0.0f);
			Assert::AreEqual(matrix.m32, 0.0f);
			Assert::AreEqual(matrix.m33, 0.0f);
		}
		TEST_METHOD(TestInitialization2)
		{
			TinyMathLib::Matrix3x3<float> matrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);

			Assert::AreEqual(matrix.m11, 1.0f);
			Assert::AreEqual(matrix.m12, 2.0f);
			Assert::AreEqual(matrix.m13, 3.0f);
			Assert::AreEqual(matrix.m21, 4.0f);
			Assert::AreEqual(matrix.m22, 5.0f);
			Assert::AreEqual(matrix.m23, 6.0f);
			Assert::AreEqual(matrix.m31, 7.0f);
			Assert::AreEqual(matrix.m32, 8.0f);
			Assert::AreEqual(matrix.m33, 9.0f);
		}
		TEST_METHOD(TestMatrixTransposition1)
		{
			TinyMathLib::Matrix3x3<float> matrixA(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
			TinyMathLib::Matrix3x3<float> matrixB = matrixA.transpose();

			Assert::AreEqual(matrixB.m11, 1.0f);
			Assert::AreEqual(matrixB.m12, 4.0f);
			Assert::AreEqual(matrixB.m13, 7.0f);

			Assert::AreEqual(matrixB.m21, 2.0f);
			Assert::AreEqual(matrixB.m22, 5.0f);
			Assert::AreEqual(matrixB.m23, 8.0f);

			Assert::AreEqual(matrixB.m31, 3.0f);
			Assert::AreEqual(matrixB.m32, 6.0f);
			Assert::AreEqual(matrixB.m33, 9.0f);
		}
		TEST_METHOD(TestMatrixTransposition2)
		{
			TinyMathLib::Matrix3x3<float> matrixA(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
			TinyMathLib::Matrix3x3<float> matrixB = matrixA.transpose();
			TinyMathLib::Matrix3x3<float> matrixC = matrixB.transpose();

			Assert::AreEqual(matrixA.m11, matrixC.m11);
			Assert::AreEqual(matrixA.m12, matrixC.m12);
			Assert::AreEqual(matrixA.m13, matrixC.m13);

			Assert::AreEqual(matrixA.m21, matrixC.m21);
			Assert::AreEqual(matrixA.m22, matrixC.m22);
			Assert::AreEqual(matrixA.m23, matrixC.m23);

			Assert::AreEqual(matrixA.m31, matrixC.m31);
			Assert::AreEqual(matrixA.m32, matrixC.m32);
			Assert::AreEqual(matrixA.m33, matrixC.m33);
		}
		TEST_METHOD(TestMatrixTransposition3)
		{
			TinyMathLib::Matrix3x3<float> matrixA(1.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 9.0f);
			TinyMathLib::Matrix3x3<float> matrixB = matrixA.transpose();

			Assert::AreEqual(matrixA.m11, matrixB.m11);
			Assert::AreEqual(matrixA.m12, matrixB.m12);
			Assert::AreEqual(matrixA.m13, matrixB.m13);

			Assert::AreEqual(matrixA.m21, matrixB.m21);
			Assert::AreEqual(matrixA.m22, matrixB.m22);
			Assert::AreEqual(matrixA.m23, matrixB.m23);

			Assert::AreEqual(matrixA.m31, matrixB.m31);
			Assert::AreEqual(matrixA.m32, matrixB.m32);
			Assert::AreEqual(matrixA.m33, matrixB.m33);
		}
		TEST_METHOD(TestMatrixMultiplicationByScalar)
		{
			TinyMathLib::Matrix3x3<float> matrixA(1.0f, 2.0f, 3.0f, 1.0f, 2.0f, 3.0f, 1.0f, 2.0f, 3.0f);
			TinyMathLib::Matrix3x3<float> matrixB = matrixA * 2.0f;

			Assert::AreEqual(matrixB.m11, 2.0f);
			Assert::AreEqual(matrixB.m12, 4.0f);
			Assert::AreEqual(matrixB.m13, 6.0f);

			Assert::AreEqual(matrixB.m21, 2.0f);
			Assert::AreEqual(matrixB.m22, 4.0f);
			Assert::AreEqual(matrixB.m23, 6.0f);

			Assert::AreEqual(matrixB.m31, 2.0f);
			Assert::AreEqual(matrixB.m32, 4.0f);
			Assert::AreEqual(matrixB.m33, 6.0f);
		}
		TEST_METHOD(TestMatrixMultiplicationByMatrix)
		{
			TinyMathLib::Matrix3x3<float> M1(1.0f, -5.0f, 3.0f, 0.0f, -2.0f, 6.0f, 7.0f, 2.0f, -4.0f);
			TinyMathLib::Matrix3x3<float> M2(-8.0f, 6.0f, 1.0f, 7.0f, 0.0f, -3.0f, 2.0f, 4.0f, 5.0f);
			TinyMathLib::Matrix3x3<float> M3 = M1 * M2;

			Assert::AreEqual(M3.m11, -37.0f);
			Assert::AreEqual(M3.m12, 18.0f);
			Assert::AreEqual(M3.m13, 31.0f);
			Assert::AreEqual(M3.m21, -2.0f);
			Assert::AreEqual(M3.m22, 24.0f);
			Assert::AreEqual(M3.m23, 36.0f);
			Assert::AreEqual(M3.m31, -50.0f);
			Assert::AreEqual(M3.m32, 26.0f);
			Assert::AreEqual(M3.m33, -19.0f);
		}
		TEST_METHOD(TestMatrixMultiplicationByIndentity1)
		{
			TinyMathLib::Matrix3x3<float> M1(0.25f, 0.5f, 0.75f, -1.0f, -2.0f, -3.0f, 1.0f, 1.0f, 1.0f);
			TinyMathLib::Matrix3x3<float> M2 = TinyMathLib::MakeIdentityMatrix3x3<float>();
			TinyMathLib::Matrix3x3<float> M3 = M1 * M2;

			Assert::AreEqual(M3.m11, M1.m11);
			Assert::AreEqual(M3.m12, M1.m12);
			Assert::AreEqual(M3.m13, M1.m13);
			Assert::AreEqual(M3.m21, M1.m21);
			Assert::AreEqual(M3.m22, M1.m22);
			Assert::AreEqual(M3.m23, M1.m23);
			Assert::AreEqual(M3.m31, M1.m31);
			Assert::AreEqual(M3.m32, M1.m32);
			Assert::AreEqual(M3.m33, M1.m33);
		}
	};

	TEST_CLASS(GeneralMatrix4x4DTesting)
	{
	public:
		TEST_METHOD(TestInitialization1)
		{
			TinyMathLib::Matrix4x4<float> matrix;

			Assert::AreEqual(matrix.m11, 0.0f);
			Assert::AreEqual(matrix.m12, 0.0f);
			Assert::AreEqual(matrix.m13, 0.0f);
			Assert::AreEqual(matrix.m14, 0.0f);
			Assert::AreEqual(matrix.m21, 0.0f);
			Assert::AreEqual(matrix.m22, 0.0f);
			Assert::AreEqual(matrix.m23, 0.0f);
			Assert::AreEqual(matrix.m24, 0.0f);
			Assert::AreEqual(matrix.m31, 0.0f);
			Assert::AreEqual(matrix.m32, 0.0f);
			Assert::AreEqual(matrix.m33, 0.0f);
			Assert::AreEqual(matrix.m34, 0.0f);
			Assert::AreEqual(matrix.m41, 0.0f);
			Assert::AreEqual(matrix.m42, 0.0f);
			Assert::AreEqual(matrix.m43, 0.0f);
			Assert::AreEqual(matrix.m44, 0.0f);
		}
		TEST_METHOD(TestInitialization2)
		{
			TinyMathLib::Matrix4x4<float> matrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);

			Assert::AreEqual(matrix.m11, 1.0f);
			Assert::AreEqual(matrix.m12, 2.0f);
			Assert::AreEqual(matrix.m13, 3.0f);
			Assert::AreEqual(matrix.m14, 4.0f);
			Assert::AreEqual(matrix.m21, 5.0f);
			Assert::AreEqual(matrix.m22, 6.0f);
			Assert::AreEqual(matrix.m23, 7.0f);
			Assert::AreEqual(matrix.m24, 8.0f);
			Assert::AreEqual(matrix.m31, 9.0f);
			Assert::AreEqual(matrix.m32, 10.0f);
			Assert::AreEqual(matrix.m33, 11.0f);
			Assert::AreEqual(matrix.m34, 12.0f);
			Assert::AreEqual(matrix.m41, 13.0f);
			Assert::AreEqual(matrix.m42, 14.0f);
			Assert::AreEqual(matrix.m43, 15.0f);
			Assert::AreEqual(matrix.m44, 16.0f);
		}
		TEST_METHOD(TestMatrixTransposition1)
		{
			TinyMathLib::Matrix4x4<float> matrixA(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
			TinyMathLib::Matrix4x4<float> matrixB = matrixA.transpose();

			Assert::AreEqual(matrixB.m11, 1.0f);
			Assert::AreEqual(matrixB.m12, 5.0f);
			Assert::AreEqual(matrixB.m13, 9.0f);
			Assert::AreEqual(matrixB.m14, 13.0f);
			Assert::AreEqual(matrixB.m21, 2.0f);
			Assert::AreEqual(matrixB.m22, 6.0f);
			Assert::AreEqual(matrixB.m23, 10.0f);
			Assert::AreEqual(matrixB.m24, 14.0f);
			Assert::AreEqual(matrixB.m31, 3.0f);
			Assert::AreEqual(matrixB.m32, 7.0f);
			Assert::AreEqual(matrixB.m33, 11.0f);
			Assert::AreEqual(matrixB.m34, 15.0f);
			Assert::AreEqual(matrixB.m41, 4.0f);
			Assert::AreEqual(matrixB.m42, 8.0f);
			Assert::AreEqual(matrixB.m43, 12.0f);
			Assert::AreEqual(matrixB.m44, 16.0f);
		}
		TEST_METHOD(TestMatrixTransposition2)
		{
			TinyMathLib::Matrix4x4<float> matrixA(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
			TinyMathLib::Matrix4x4<float> matrixB = matrixA.transpose();
			TinyMathLib::Matrix4x4<float> matrixC = matrixB.transpose();

			Assert::AreEqual(matrixA.m11, matrixC.m11);
			Assert::AreEqual(matrixA.m12, matrixC.m12);
			Assert::AreEqual(matrixA.m13, matrixC.m13);
			Assert::AreEqual(matrixA.m14, matrixC.m14);
			Assert::AreEqual(matrixA.m21, matrixC.m21);
			Assert::AreEqual(matrixA.m22, matrixC.m22);
			Assert::AreEqual(matrixA.m23, matrixC.m23);
			Assert::AreEqual(matrixA.m24, matrixC.m24);
			Assert::AreEqual(matrixA.m31, matrixC.m31);
			Assert::AreEqual(matrixA.m32, matrixC.m32);
			Assert::AreEqual(matrixA.m33, matrixC.m33);
			Assert::AreEqual(matrixA.m34, matrixC.m34);
			Assert::AreEqual(matrixA.m41, matrixC.m41);
			Assert::AreEqual(matrixA.m42, matrixC.m42);
			Assert::AreEqual(matrixA.m43, matrixC.m43);
			Assert::AreEqual(matrixA.m44, matrixC.m44);
		}
		TEST_METHOD(TestMatrixTransposition3)
		{
			TinyMathLib::Matrix4x4<float> matrixA(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.0f, 11.0f, 0.0f, 0.0f, 0.0f, 0.0f, 16.0f);
			TinyMathLib::Matrix4x4<float> matrixB = matrixA.transpose();

			Assert::AreEqual(matrixA.m11, matrixB.m11);
			Assert::AreEqual(matrixA.m12, matrixB.m12);
			Assert::AreEqual(matrixA.m13, matrixB.m13);
			Assert::AreEqual(matrixA.m14, matrixB.m14);

			Assert::AreEqual(matrixA.m21, matrixB.m21);
			Assert::AreEqual(matrixA.m22, matrixB.m22);
			Assert::AreEqual(matrixA.m23, matrixB.m23);
			Assert::AreEqual(matrixA.m24, matrixB.m24);

			Assert::AreEqual(matrixA.m31, matrixB.m31);
			Assert::AreEqual(matrixA.m32, matrixB.m32);
			Assert::AreEqual(matrixA.m33, matrixB.m33);
			Assert::AreEqual(matrixA.m34, matrixB.m34);

			Assert::AreEqual(matrixA.m41, matrixB.m41);
			Assert::AreEqual(matrixA.m42, matrixB.m42);
			Assert::AreEqual(matrixA.m43, matrixB.m43);
			Assert::AreEqual(matrixA.m44, matrixB.m44);
		}
		TEST_METHOD(TestMatrixMultiplicatoinByScalar1)
		{
			TinyMathLib::Matrix4x4<float> matrixA(1.0f, 2.0f, 3.0f, 4.0f, 1.0f, 2.0f, 3.0f, 4.0f, 1.0f, 2.0f, 3.0f, 4.0f, 1.0f, 2.0f, 3.0f, 4.0f);
			TinyMathLib::Matrix4x4<float> matrixB = matrixA * 2.0f;

			Assert::AreEqual(matrixB.m11, 2.0f);
			Assert::AreEqual(matrixB.m12, 4.0f);
			Assert::AreEqual(matrixB.m13, 6.0f);
			Assert::AreEqual(matrixB.m14, 8.0f);

			Assert::AreEqual(matrixB.m21, 2.0f);
			Assert::AreEqual(matrixB.m22, 4.0f);
			Assert::AreEqual(matrixB.m23, 6.0f);
			Assert::AreEqual(matrixB.m24, 8.0f);

			Assert::AreEqual(matrixB.m31, 2.0f);
			Assert::AreEqual(matrixB.m32, 4.0f);
			Assert::AreEqual(matrixB.m33, 6.0f);
			Assert::AreEqual(matrixB.m34, 8.0f);

			Assert::AreEqual(matrixB.m41, 2.0f);
			Assert::AreEqual(matrixB.m42, 4.0f);
			Assert::AreEqual(matrixB.m43, 6.0f);
			Assert::AreEqual(matrixB.m44, 8.0f);
		}
		TEST_METHOD(TestMatrixMultiplicatoinByMatrix1)
		{
			TinyMathLib::Matrix4x4<float> matrixA(5.0f, 7.0f, 9.0f, 10.0f, 2.0f, 3.0f, 3.0f, 8.0f, 8.0f, 10.0f, 2.0f, 3.0f, 3.0f, 3.0f, 4.0f, 8.0f);
			TinyMathLib::Matrix4x4<float> matrixB(3.0f, 10.0f, 12.0f, 18.0f, 12.0f, 1.0f, 4.0f, 9.0f, 9.0f, 10.0f, 12.0f, 2.0f, 3.0f, 12.0f, 4.0f, 10.0f);
			TinyMathLib::Matrix4x4<float> matrixC = matrixA * matrixB;

			Assert::AreEqual(210.0f, matrixC.m11);
			Assert::AreEqual(267.0f, matrixC.m12);
			Assert::AreEqual(236.0f, matrixC.m13);
			Assert::AreEqual(271.0f, matrixC.m14);

			Assert::AreEqual(93.0f, matrixC.m21);
			Assert::AreEqual(149.0f, matrixC.m22);
			Assert::AreEqual(104.0f, matrixC.m23);
			Assert::AreEqual(149.0f, matrixC.m24);

			Assert::AreEqual(171.0f, matrixC.m31);
			Assert::AreEqual(146.0f, matrixC.m32);
			Assert::AreEqual(172.0f, matrixC.m33);
			Assert::AreEqual(268.0f, matrixC.m34);

			Assert::AreEqual(105.0f, matrixC.m41);
			Assert::AreEqual(169.0f, matrixC.m42);
			Assert::AreEqual(128.0f, matrixC.m43);
			Assert::AreEqual(169.0f, matrixC.m44);
		}
		TEST_METHOD(TestMatrixMultiplicationByIdentity1)
		{
			TinyMathLib::Matrix4x4<float> M1(1.25f, 2.25f, 3.35f, 4.25f, 0.1f, 0.2f, 0.3f, 0.4f, 1.0f, 2.0f, 3.0f, 4.0f, -1.0f, -2.0f, -3.0f, -4.0f);
			TinyMathLib::Matrix4x4<float> M2 = TinyMathLib::MakeIdentityMatrix4x4<float>();
			TinyMathLib::Matrix4x4<float> M3 = M1 * M2;

			Assert::AreEqual(M3.m11, M1.m11);
			Assert::AreEqual(M3.m12, M1.m12);
			Assert::AreEqual(M3.m13, M1.m13);
			Assert::AreEqual(M3.m14, M1.m14);
			Assert::AreEqual(M3.m21, M1.m21);
			Assert::AreEqual(M3.m22, M1.m22);
			Assert::AreEqual(M3.m23, M1.m23);
			Assert::AreEqual(M3.m24, M1.m24);
			Assert::AreEqual(M3.m31, M1.m31);
			Assert::AreEqual(M3.m32, M1.m32);
			Assert::AreEqual(M3.m33, M1.m33);
			Assert::AreEqual(M3.m34, M1.m34);
			Assert::AreEqual(M3.m41, M1.m41);
			Assert::AreEqual(M3.m42, M1.m42);
			Assert::AreEqual(M3.m43, M1.m43);
			Assert::AreEqual(M3.m44, M1.m44);
		}
	};
}
