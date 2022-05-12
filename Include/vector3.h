#include "defines.h"
#include "math.h"

//TODO: Make Define Header for RenderMath

template<typename T>
struct TVec3 {
    union {
        struct {
            T x;
            T y;
            T z;
        };
        T v[3];
    };

	inline TVec3<T>() : x((T)0), y((T) 0), z((T)0){};

	inline TVec3<T>(T _x, T _y, T _z) : x(_x), y(_y), z(_z){}

	/*
	* Overload the bracket operator to allow access to the Components
	*/
	T& operator [] (int i)
	{
		return ((&x)[i]);
	}

	const T& operator [] (int i) const
	{
		return ((&x)[i]);
	}

	 TVec3<T>& operator *=(float s)
	 {
	 	x *= s;
	 	y *= s;
	 	z *= s;

	 	return(*this);
	 }

	 TVec3<T>& operator /=(float s)
	 {
	 	s = 1.0f / s;
	 	x *= s;
	 	y *= s;
	 	z *= s;

	 	return(*this);
	 }


	 TVec3<T>& operator +=(const TVec3<T>& v)
	 {
	 	x += v.x;
	 	y += v.y;
	 	z += v.z;
	 	return (*this);
	 }

	 TVec3<T>& operator -=(const TVec3<T>& v)
	 {
	 	x -= v.x;
	 	y -= v.y;
	 	z -= v.z;
	 	return (*this);
	 }
};

typedef TVec3<float> FVec3;
typedef TVec3<int> IVec3;
typedef TVec3<unsigned int> UVec3;

FVec3 operator *(const FVec3& v, float s);

FVec3 operator / (const FVec3& v, float s);

FVec3 operator - (const FVec3& v);

FVec3 operator + (const FVec3& a, const FVec3& b);

FVec3 operator - (const FVec3& a, const FVec3& b);

float Magnitude(const FVec3& v);

FVec3 Normalize(const FVec3& v);

IVec3 operator *(const IVec3& v, float s);

IVec3 operator / (const IVec3& v, float s);

IVec3 operator - (const IVec3& v);

IVec3 operator + (const IVec3& a, const IVec3& b);

IVec3 operator - (const IVec3& a, const IVec3& b);

float Magnitude(const IVec3& v);

IVec3 Normalize(const IVec3& v);

UVec3 operator *(const UVec3& v, float s);

UVec3 operator / (const UVec3& v, float s);

UVec3 operator - (const UVec3& v);

UVec3 operator + (const UVec3& a, const UVec3& b);

UVec3 operator - (const UVec3& a, const UVec3& b);

float Magnitude(const UVec3& v);

UVec3 Normalize(const UVec3& v);
