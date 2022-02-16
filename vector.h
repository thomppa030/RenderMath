#include <corecrt_math.h>
#include <math.h>

#define VEC_EPSILON 0.000001f

struct Vector3
{
	union {
		float x;
		float y;
		float z;
	}; 
	float v[3];

	Vector3() = default;

	Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	/*
	* Overload the bracket operator to allow access to the Components
	*/
	float& operator [] (int i)
	{
		return ((&x)[i]);
	}

	const float& operator [] (int i) const
	{
		return ((&x)[i]);
	}

	 Vector3& operator *=(float s)
	 {
	 	x *= s;
	 	y *= s;
	 	z *= s;

	 	return(*this);
	 }

	 Vector3& operator /=(float s)
	 {
	 	s = 1.0f / s;
	 	x *= s;
	 	y *= s;
	 	z *= s;

	 	return(*this);
	 }


	 Vector3& operator +=(const Vector3& v)
	 {
	 	x += v.x;
	 	y += v.y;
	 	z += v.z;
	 	return (*this);
	 }

	 Vector3& operator -=(const Vector3& v)
	 {
	 	x -= v.x;
	 	y -= v.y;
	 	z -= v.z;
	 	return (*this);
	 }
};

inline Vector3 operator *(const Vector3& v, float s)
{
	return (Vector3(v.x * s, v.y * s, v.z *s));
}

inline Vector3 operator / (const Vector3& v, float s)
{
	s = 1.0f / s;
	return (Vector3(v.x * s, v.y * s, v.z *s));
}

inline Vector3 operator - (const Vector3& v)
{
	return (Vector3(-v.x, -v.y, -v.z));
}

inline Vector3 operator + (const Vector3& a, const Vector3& b)
{
	return (Vector3(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3 operator - (const Vector3& a, const Vector3& b)
{
	return (Vector3(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline float Magnitude(const Vector3& v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3 Normalize(const Vector3& v)
{
	return (v / Magnitude(v));
}

struct Vector2
{
	float x , y;


	Vector2() = default;

	Vector2(float _x, float _y)
	{
		 x = _x;
		 y = _y;
	}

	float& operator [] (int i)
	{
		return ((&x)[i]);
	}

	const float& operator [] (int i) const
	{
		return ((&x)[i]);
	}

};

inline Vector2 operator * (const Vector2& v, float s)
{
	return (Vector2(v.x *s , v.y * s));
}

inline Vector2 operator / (const Vector2& v, float s)
{
	s = 1.0f /s;
	return (Vector2(v.x *s , v.y * s));
}

inline Vector2 operator - (const Vector2& v)
{
	return (Vector2(-v.x, -v.y));
}

inline float Magnitude(const Vector2& v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

inline Vector2 Normalize(const Vector2 &v)
{
	return (v / Magnitude(v));
}

