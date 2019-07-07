#pragma once

#include <sstream>
#include <math.h>

// Rules - identities needs to be unit-tested!!!!
// Commit this as a separate project on GitHub
// Commit along with unit tests and good documentation
// It should be a one-header tiny library by definition

// Natural numbers, Integers, Rational numbers, Real numbers
// 2D Cartesian Space, Cartesian Coordinates
// 3D Cartesian Space, Left-Handed Coordinate Spaces, Right-Handed Coordinate Spaces, Roatation also differs (left-hand rule)
// Scalar - ordinary number
// Vector - array of numbers
// Dimension of a vector - how many numbers vector contains
// Magnitude - length of a vector
// Direction - which way a vector is pointing in space
// Vectors do not have positions - only magnitude and direction
// Point has location but no real size or thickness
// Vector has magnitude and direction, but no position

// Our Matrix is RxC (rows by columns)
// An r x n matrix may be multiplied by an n x c matrix and the result is an r x c matrix.
// For now we only support 2x2, 3x3 and 4x4 matrices, so basically you can only multiply them by themselves.

// This library uses ROW VECTORS (at leas for now).

// Linear transformation do not contain translation. A transformation that contains translation is known as an affine transformation.

// TODO:
// - add printing for matrices
// - add possiblility to multiply integer vectors by float matrices

namespace TinyMathLib
{
	constexpr auto PI = 3.141592f;

	template<typename T>
	class Matrix2x2
	{
	public:
		Matrix2x2() : m11(0), m12(0), m21(0), m22(0)
		{
		}
		Matrix2x2(T _m11, T _m12, T _m21, T _m22)
			: m11(_m11), m12(_m12), m21(_m21), m22(_m22)
		{
		}
		Matrix2x2<T> transpose()
		{
			return Matrix2x2(m11, m21, m12, m22);
		}
		Matrix2x2<T> operator*(T scalar)
		{
			return Matrix2x2(m11 * scalar, m12 * scalar, m21 * scalar, m22 * scalar);
		}
		Matrix2x2<T> operator*(Matrix2x2<T> matrix)
		{
			return Matrix2x2((m11 * matrix.m11 + m12 * matrix.m21), (m11 * matrix.m12 + m12 * matrix.m22), (m21 * matrix.m11 + m22 * matrix.m21), (m21 * matrix.m12 + m22 * matrix.m22));
		}
	public:
		T m11, m12, m21, m22;
	};

	template<typename T>
	class Matrix3x3
	{
	public:
		Matrix3x3() : m11(0), m12(0), m13(0), m21(0), m22(0), m23(0), m31(0), m32(0), m33(0)
		{
		}
		Matrix3x3(T _m11, T _m12, T _m13, T _m21, T _m22, T _m23, T _m31, T _m32, T _m33)
			: m11(_m11), m12(_m12), m13(_m13), m21(_m21), m22(_m22), m23(_m23), m31(_m31), m32(_m32), m33(_m33)
		{
		}
		// Again, should I return or operate on myself??
		Matrix3x3<T> transpose()
		{
			return Matrix3x3(m11, m21, m31, m12, m22, m32, m13, m23, m33);
		}
		Matrix3x3<T> operator*(T scalar)
		{
			return Matrix3x3(m11 * scalar, m12 * scalar, m13 * scalar, m21 * scalar, m22 * scalar, m23 * scalar, m31 * scalar, m32 * scalar, m33 * scalar);
		}
		Matrix3x3<T> operator*(Matrix3x3<T> matrix)
		{
			return Matrix3x3(
				(m11 * matrix.m11 + m12 * matrix.m21 + m13 * matrix.m31),
				(m11 * matrix.m12 + m12 * matrix.m22 + m13 * matrix.m32),
				(m11 * matrix.m13 + m12 * matrix.m23 + m13 * matrix.m33),

				(m21 * matrix.m11 + m22 * matrix.m21 + m23 * matrix.m31),
				(m21 * matrix.m12 + m22 * matrix.m22 + m23 * matrix.m32),
				(m21 * matrix.m13 + m22 * matrix.m23 + m23 * matrix.m33),

				(m31 * matrix.m11 + m32 * matrix.m21 + m33 * matrix.m31),
				(m31 * matrix.m12 + m32 * matrix.m22 + m33 * matrix.m32),
				(m31 * matrix.m13 + m32 * matrix.m23 + m33 * matrix.m33)
			);
		}
	public:
		T m11, m12, m13, m21, m22, m23, m31, m32, m33;
	};

	template<typename T>
	class Matrix4x4
	{
	public:
		Matrix4x4() : m11(0), m12(0), m13(0), m14(0), m21(0), m22(0), m23(0), m24(0), m31(0), m32(0), m33(0), m34(0), m41(0), m42(0), m43(0), m44(0)
		{
		}
		Matrix4x4(T _m11, T _m12, T _m13, T _m14, T _m21, T _m22, T _m23, T _m24, T _m31, T _m32, T _m33, T _m34, T _m41, T _m42, T _m43, T _m44)
			: m11(_m11), m12(_m12), m13(_m13), m14(_m14), m21(_m21), m22(_m22), m23(_m23), m24(_m24), m31(_m31), m32(_m32), m33(_m33), m34(_m34), m41(_m41), m42(_m42), m43(_m43), m44(_m44)
		{
		}
		Matrix4x4<T> transpose()
		{
			return Matrix4x4(m11, m21, m31, m41, m12, m22, m32, m42, m13, m23, m33, m43, m14, m24, m34, m44);
		}
		Matrix4x4<T> operator*(T scalar)
		{
			return Matrix4x4(m11 * scalar, m12 * scalar, m13 * scalar, m14 * scalar, m21 * scalar, m22 * scalar, m23 * scalar, m24 * scalar, m31 * scalar, m32 * scalar, m33 * scalar, m34 * scalar, m41 * scalar, m42 * scalar, m43 * scalar, m44 * scalar);
		}
		Matrix4x4<T> operator*(Matrix4x4<T> matrix)
		{
			return Matrix4x4(
				(m11 * matrix.m11 + m12 * matrix.m21 + m13 * matrix.m31 + m14 * matrix.m41),
				(m11 * matrix.m12 + m12 * matrix.m22 + m13 * matrix.m32 + m14 * matrix.m42),
				(m11 * matrix.m13 + m12 * matrix.m23 + m13 * matrix.m33 + m14 * matrix.m43),
				(m11 * matrix.m14 + m12 * matrix.m24 + m13 * matrix.m34 + m14 * matrix.m44),

				(m21 * matrix.m11 + m22 * matrix.m21 + m23 * matrix.m31 + m24 * matrix.m41),
				(m21 * matrix.m12 + m22 * matrix.m22 + m23 * matrix.m32 + m24 * matrix.m42),
				(m21 * matrix.m13 + m22 * matrix.m23 + m23 * matrix.m33 + m24 * matrix.m43),
				(m21 * matrix.m14 + m22 * matrix.m24 + m23 * matrix.m34 + m24 * matrix.m44),

				(m31 * matrix.m11 + m32 * matrix.m21 + m33 * matrix.m31 + m34 * matrix.m41),
				(m31 * matrix.m12 + m32 * matrix.m22 + m33 * matrix.m32 + m34 * matrix.m42),
				(m31 * matrix.m13 + m32 * matrix.m23 + m33 * matrix.m33 + m34 * matrix.m43),
				(m31 * matrix.m14 + m32 * matrix.m24 + m33 * matrix.m34 + m34 * matrix.m44),

				(m41 * matrix.m11 + m42 * matrix.m21 + m43 * matrix.m31 + m44 * matrix.m41),
				(m41 * matrix.m12 + m42 * matrix.m22 + m43 * matrix.m32 + m44 * matrix.m42),
				(m41 * matrix.m13 + m42 * matrix.m23 + m43 * matrix.m33 + m44 * matrix.m43),
				(m41 * matrix.m14 + m42 * matrix.m24 + m43 * matrix.m34 + m44 * matrix.m44)
			);
		}
	public:
		T m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
	};

	template<typename T>
	class Vector2D
	{
	public:
		Vector2D() : x(0), y(0)
		{
		}
		Vector2D(T _x, T _y) : x(_x), y(_y)
		{
		}
		// Vector Negation
		Vector2D operator-()
		{
			return Vector2D(-x, -y);
		}
		// Vector Multiplication by Scalar
		Vector2D operator*(T scalar) const
		{
			return Vector2D(x * scalar, y * scalar);
		}
		// Vector Multiplcation by Vector
		Vector2D operator*(const Vector2D& vector) const
		{
			return Vector2D(x * vector.x, y * vector.y);
		}
		// Vector Multiplication by Matrix
		Vector2D operator*(const Matrix2x2<T>& matrix)
		{
			return Vector2D((x * matrix.m11 + y * matrix.m21), (x * matrix.m12 + y * matrix.m22));
		}
		// Vector Division by Scalar
		Vector2D operator/(T scalar) const
		{
			return Vector2D(x / scalar, y / scalar);
		}
		// Vector Division by Vector
		Vector2D operator/(const Vector2D& vector) const
		{
			return Vector2D(x / vector.x, y / vector.y);
		}
		// Vector Addition
		Vector2D operator+(const Vector2D& vector)
		{
			return Vector2D(x + vector.x, y + vector.y);
		}
		// Vector Substraction
		Vector2D operator-(const Vector2D& vector) const
		{
			return Vector2D(x - vector.x, y - vector.y);
		}
		// Dot Product
		T dotProduct(const Vector2D& vector) const
		{
			return (x * vector.x) + (y * vector.y);
		}
		// Vector Magnitude (length)
		// - why float and not double??
		float length() const
		{
			return sqrt((x * x) + (y * y));
		}
		// Normalizing a Vector
		// - do we return or operate on the vector itself??
		Vector2D normalize()
		{
			return *this / this->length();
		}
		friend std::ostream& operator<< (std::ostream& out, const Vector2D& obj)
		{
			out << "[" << obj.x << ", " << obj.y << "]";
			return out;
		}
	public:
		T x, y;
	};

	template<typename T>
	class Vector3D
	{
	public:
		Vector3D() : x(0), y(0), z(0)
		{
		}
		Vector3D(T _x, T _y, T _z) : x(_x), y(_y), z(_z)
		{
		}
		// Vector Negation
		Vector3D operator-()
		{
			return Vector3D(-x, -y, -z);
		}
		// Vector Multiplicaton by Scalar
		Vector3D operator*(T scalar) const
		{
			return Vector3D(x * scalar, y * scalar, z * scalar);
		}
		// Vector Multiplication by Vector
		Vector3D operator*(const Vector3D& vector) const
		{
			return Vector3D(x * vector.x, y * vector.y, z * vector.z);
		}
		// Vector Multiplication by Matrix3x3
		Vector3D operator*(const Matrix3x3<T>& matrix)
		{
			return Vector3D((x * matrix.m11 + y * matrix.m21 + z * matrix.m31), (x * matrix.m12 + y * matrix.m22 + z * matrix.m32), (x * matrix.m13 + y * matrix.m23 + z * matrix.m33));
		}
		// Vector Division by Scalar
		Vector3D operator/(T scalar) const
		{
			return Vector3D(x / scalar, y / scalar, z / scalar);
		}
		// Vector Division by Vector
		Vector3D operator/(const Vector3D& vector) const
		{
			return Vector3D(x / vector.x, y / vector.y, z / vector.z);
		}
		// Vector Addition
		Vector3D operator+(const Vector3D& vector)
		{
			return Vector3D(x + vector.x, y + vector.y, z + vector.z);
		}
		// Vector Substraction
		Vector3D operator-(const Vector3D& vector) const
		{
			return Vector3D(x - vector.x, y - vector.y, z - vector.z);
		}
		// Dot Product
		T dotProduct(const Vector3D& vector)
		{
			return (x * vector.x) + (y * vector.y) + (z * vector.z);
		}
		// Cross Product
		Vector3D crossProduct(const Vector3D& vector) const
		{
			return Vector3D((y * vector.z) - (z * vector.y), (z * vector.x) - (x * vector.z), (x * vector.y) - (y * vector.x));
		}
		// Vector Magnitude (length)
		// - why float and not double??
		float length()
		{
			return sqrt((x * x) + (y * y) + (z * z));
		}
		// Normalize a Vector
		// - do we return or operate on the vector itself??
		Vector3D normalize()
		{
			return *this / this->length();
		}
		friend std::ostream& operator<< (std::ostream& out, const Vector3D& obj)
		{
			out << "[" << obj.x << ", " << obj.y << ", " << obj.z << "]";
			return out;
		}
	public:
		T x, y, z;
	};

	// Converts Degrees to Radians
	float convertToRadians(float degrees)
	{
		return degrees * (PI / 180.0f);
	}

	float convertToDegrees(float radians)
	{
		return radians * (180 / PI);
	}

	// Same thing here - do we return or operate on the vector??
	template<typename T>
	Vector2D<T> normalize(const Vector2D<T>& vector)
	{
		return vector / vector.length();
	}

	template<typename T>
	Vector3D<T> normalize(const Vector3D<T>& vector)
	{
		return vector / vector.length();
	}

	template<typename T>
	float length(const Vector2D<T>& vector)
	{
		return sqrt((vector.x * vector.x) + (vector.y * vector.y));
	}

	template<typename T>
	float length(const Vector3D<T>& vector)
	{
		return sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	}

	template<typename T>
	float distance(const Vector2D<T>& a, const Vector2D<T>& b)
	{
		return length(b - a);
	}

	template<typename T>
	float distance(const Vector3D<T>& a, const Vector3D<T>& b)
	{
		return length(b - a);
	}

	// Calculates dot product for two 2D vectors.
	// Dot product of two unit vectors is equal to the cosine of the angle between them.
	// The dot product of two vectors is equal to the cosine of the angle between them, multiplied by the lenghts of them.
	// The dot product measures the length of the projection of second vector onto the first one, multiplied by the lenght of the first one.
	template<typename T>
	T dotProduct(const Vector2D<T>& a, const Vector2D<T>& b)
	{
		return (a.x * b.x) + (a.y * b.y);
	}

	// Calculates dot product for two 3D vectors.
	// Dot product of two unit vectors is equal to the cosine of the angle between them.
	// The dot product of two vectors is equal to the cosine of the angle between them, multiplied by the lenghts of them.
	// The dot product measures the length of the projection of second vector onto the first one, multiplied by the lenght of the first one.
	template<typename T>
	T dotProduct(const Vector3D<T>& a, const Vector3D<T>& b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}

	// Calculated cross product for two 3D vectors.
	// Cross product yields a vector that is parpendicular to the orginal two vectors.
	template<typename T>
	Vector3D<T> crossProduct(const Vector3D<T>& a, const Vector3D<T>& b)
	{
		return Vector3D<T>((a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x));
	}

	template<typename T>
	Vector3D<T> MakeZeroVector3D()
	{
		return Vector3D<T>(0, 0, 0);
	}

	template<typename T>
	Vector2D<T> MakeZeroVector2D()
	{
		return Vector2D<T>(0, 0, 0);
	}

	template<typename T>
	Matrix2x2<T> MakeIdentityMatrix2x2()
	{
		return Matrix2x2<T>(1.0f, 0.0f, 0.0f, 1.0f);
	}

	template<typename T>
	Matrix3x3<T> MakeIdentityMatrix3x3()
	{
		return Matrix3x3<T>(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	}

	template<typename T>
	Matrix4x4<T> MakeIdentityMatrix4x4()
	{
		return Matrix4x4<T>(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	}

	// Consider counterclockwise rotation positive and clockwise rotation negative.
	template<typename T>
	Matrix2x2<T> CreateRotationMatrix(float angle)
	{
		return Matrix2x2<T>(cos(angle), sin(angle), -sin(angle), cos(angle));
	}

	// This library is using left-hand rule for determining "positive" and "negative" rotation
	template<typename T>
	Matrix3x3<T> CreateRotationMatrixAxisX(float angle)
	{
		return Matrix3x3<T>(1, 0, 0, 0, cos(angle), sin(angle), 0, -sin(angle), cos(angle));
	}

	template<typename T>
	Matrix3x3<T> CreateRotationMatrix3x3AxisY(float angle)
	{
		return Matrix3x3<T>(cos(angle), 0, -sin(angle), 0, 1, 0, sin(angle), 0, cos(angle));
	}

	template<typename T>
	Matrix3x3<T> CreateRotationMatrix3x3AxisZ(float angle)
	{
		return Matrix3x3<T>(cos(angle), sin(angle), 0, -sin(angle), cos(angle), 0, 0, 0, 1);
	}

	template<typename T>
	Matrix3x3<T> CreateRotationMatrix3x3(float angle, Vector3D<T> unitAxis)
	{
		return Matrix3x3<T>(
			(unitAxis.x * unitAxis.x) * (1 - cos(angle)) +                cos(angle), (unitAxis.x * unitAxis.y) * (1 - cos(angle)) + (unitAxis.z * sin(angle)), (unitAxis.x * unitAxis.z) * (1 - cos(angle)) - (unitAxis.y * sin(angle)),
			(unitAxis.x * unitAxis.y) * (1 - cos(angle)) - (unitAxis.z * sin(angle)), (unitAxis.y * unitAxis.y) * (1 - cos(angle)) +                cos(angle), (unitAxis.y * unitAxis.z) * (1 - cos(angle)) + (unitAxis.x * sin(angle)),
			(unitAxis.x * unitAxis.z) * (1 - cos(angle)) + (unitAxis.y * sin(angle)), (unitAxis.y * unitAxis.z) * (1 - cos(angle)) - (unitAxis.x * sin(angle)), (unitAxis.z * unitAxis.z) * (1 - cos(angle)) + cos(angle)
		);
	}

	template<typename T>
	Matrix2x2<T> CreateScaleMatrix2x2(float scaleX, float scaleY)
	{
		return Matrix2x2<T>(scaleX, 0, 0, scaleY);
	}

	template<typename T>
	Matrix3x3<T> CreateScaleMatrix3x3(float scaleX, float scaleY, float scaleZ)
	{
		return Matrix3x3<T>(
			scaleX, 0, 0,
			0, scaleY, 0,
			0, 0, scaleZ
		);
	}

	template<typename T>
	Matrix2x2<T> CreateScaleMatrix2x2(float scale, TinyMathLib::Vector2D<T> direction)
	{
		return Matrix2x2<T>(
			1 + (scale - 1) * direction.x * direction.x,     (scale - 1) * direction.x * direction.y,
			    (scale - 1) * direction.x * direction.y, 1 + (scale - 1) * direction.y * direction.y
		);
	}

	template<typename T>
	Matrix3x3<T> CreateScaleMatrix3x3(float scale, TinyMathLib::Vector3D<T> direction)
	{
		return Matrix3x3<T>(
			1 + (scale - 1) * direction.x * direction.x, (scale - 1) * direction.x * direction.y, (scale - 1) * direction.x * direction.z,
			(scale - 1) * direction.y * direction.x, 1 + (scale - 1) * direction.y * direction.y, (scale - 1) * direction.y * direction.z,
			(scale - 1) * direction.z * direction.x, (scale - 1) * direction.z * direction.y, 1 + (scale - 1) * direction.z * direction.z
		);
	}

	template<typename T>
	Matrix3x3<T> CreateOrtographicProjectionMatrixXY3x3()
	{
		return Matrix3x3<T>(1, 0, 0, 0, 1, 0, 0, 0, 0);
	}

	template<typename T>
	Matrix3x3<T> CreateOrtographicProjectionMatrixXZ3x3()
	{
		return Matrix3x3<T>(1, 0, 0, 0, 0, 0, 0, 0, 1);
	}

	template<typename T>
	Matrix3x3<T> CreateOrtographicProjectionMatrixYZ3x3()
	{
		return Matrix3x3<T>(
			0, 0, 0,
			0, 1, 0,
			0, 0, 1
		);
	}

	template<typename T>
	Matrix3x3<T> CreateOrtographicProjectionMatrix3x3(TinyMathLib::Vector3D<T> normal)
	{
		return Matrix3x3<T>(
			+1 - normal.x * normal.x, -1 * normal.x * normal.y, -1 * normal.x * normal.z,
			-1 * normal.y * normal.x, +1 - normal.y * normal.y, -1 * normal.y * normal.z,
			-1 * normal.z * normal.x, -1 * normal.z * normal.y, +1 - normal.z * normal.z
		);
	}
}