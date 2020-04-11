#pragma once
#include <cmath>
#include <algorithm>
#include <vector>

template<typename T>
T sq(T x) { return x * x; }

template<typename T>
class Vec2
{
public:
	Vec2() = default;
	Vec2(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	}
	template<typename S>
	Vec2(const Vec2<S>& src)
		:
		x((T)src.x),
		y((T)src.y)
	{
	}
	Vec2 operator+(const Vec2& rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}
	Vec2 operator+(const T rhs) const
	{
		return Vec2(x + rhs, y + rhs);
	}
	Vec2& operator+=(const Vec2& rhs)
	{
		return *this = *this + rhs;
	}
	Vec2& operator+=(const T rhs)
	{
		return *this = *this + rhs;
	}
	T operator*(const Vec2& rhs) const//dot product
	{
		return x * rhs.x + y * rhs.y;
	}
	Vec2 operator*(T rhs) const
	{
		return Vec2(x * rhs, y * rhs);
	}
	Vec2& operator*=(T rhs)
	{
		return *this = *this * rhs;
	}
	Vec2 operator-() const
	{
		Vec2 v;
		v.x = -x;
		v.y = -y;
		return v;
	}
	Vec2 operator-(const Vec2& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}

	Vec2 operator-(const T rhs) const
	{
		return Vec2(x - rhs, y - rhs);
	}
	Vec2& operator-=(const Vec2& rhs)
	{
		return *this = *this - rhs;
	}
	Vec2& operator-=(const T rhs)
	{
		return *this = *this - rhs;
	}
	bool operator==(const Vec2& rhs)
	{
		return rhs.x == x && rhs.y == rhs.y;
	}
	bool operator!=(const Vec2& rhs)
	{
		return !((*this) == rhs);
	}
	T getLength() const
	{
		return (T)std::sqrt(getLengthSq());
	}
	T getLengthSq() const
	{
		return x * x + y * y;
	}
	Vec2& normalize()
	{
		return *this = getNormalized();
	}
	Vec2 getNormalized() const
	{
		const T len = getLength();
		if (len != (T)0)
		{
			return *this * ((T)1 / len);
		}
		return *this;
	}
	static Vec2 zero()
	{
		return{ (T)0,(T)0 };
	}
public:
	T x;
	T y;
};

typedef Vec2<int> VecI2;
typedef Vec2<float> VecF2;

template<typename T, typename S>
S getDistanceSq(const T& obj, const Vec2<S>& point)
{
	return (obj.getPosConst() - point).getLengthSq();
}

template<typename T>
Vec2<T> getInBounds(const Vec2<T>& point, const Vec2<T>& leftBound, const Vec2<T>& rightBound)
{
	if (point < leftBound)
		return leftBound;
	if (point > rightBound)
		return rightBound;
	return point;
}
