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

    TVec2<T> operator* (float s)
    {
        return TVec2<T>{x*s, y*s};
    }

    TVec2<T>& operator*=(float s)
    {
        x *= s;
        y *= s;
        return(*this);
    }

    TVec2<T> operator/ (float s)
    {
        s = 1/s;
        return TVec2<T>{x*s, y*s};
    }

    TVec2<T>& operator/=(float s)
    {
        s = 1/s;
        x *= s;
        x *= s;
        return(*this);
    }

    TVec2<T>& operator - (const TVec2<T>& v)
    {
        x = -x;
        y = y;
	    return (*this);
    }
};

typedef TVec2<float> FVec2;
typedef TVec2<int> IVec2;
typedef TVec2<unsigned int> UVec2;

inline FVec2 operator - (const FVec2& v)
{
	return (FVec2(-v.x, -v.y));
}

template <typename T>
inline float Magnitude(const TVec2<T>& v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

template <typename T>
inline TVec2<T> Normalize(const TVec2<T> &v)
{
	return (v / Magnitude(v));
}

template <typename T> inline float dot(const TVec2<T> &l, const TVec2<T> &r) {
    return l.x * r.x + l.y * r.y;
}