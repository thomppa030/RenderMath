//
// Created by kprie on 11.05.2022.
//
#include "defines.h"
#include "math.h"

template<typename T>
struct TVec2
{
    union {
        struct {
            T x;
            T y;
        };
        T v[2];
    };

    TVec2<T>() : x((T)0), y((T)0){};

    TVec2<T>(T _x,T _y) : x(_x), y(_y){};

    T& operator [] (int i)
    {
        return ((&x)[i]);
    }

    const T& operator [] (int i) const
    {
        return ((&x)[i]);
    }

};

typedef TVec2<float> FVec2;
typedef TVec2<int> IVec2;
typedef TVec2<unsigned int> UVec2;

inline FVec2 operator * (const FVec2& v, float s)
{
	return (FVec2(v.x *s , v.y * s));
}

inline FVec2 operator / (const FVec2& v, float s)
{
	s = 1.0f /s;
	return (FVec2(v.x *s , v.y * s));
}

inline FVec2 operator - (const FVec2& v)
{
	return (FVec2(-v.x, -v.y));
}

inline float Magnitude(const FVec2& v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

inline FVec2 Normalize(const FVec2 &v)
{
	return (v / Magnitude(v));
}

