//
// Created by kprie on 11.05.2022.
//
#include "vector3.h"

FVec3 operator *(const FVec3& v, float s)
{
	return (FVec3(v.x * s, v.y * s, v.z *s));
}

FVec3 operator / (const FVec3& v, float s)
{
	s = 1.0f / s;
	return (FVec3(v.x * s, v.y * s, v.z *s));
}

FVec3 operator - (const FVec3& v)
{
	return (FVec3(-v.x, -v.y, -v.z));
}

FVec3 operator + (const FVec3& a, const FVec3& b)
{
	return (FVec3(a.x + b.x, a.y + b.y, a.z + b.z));
}

FVec3 operator - (const FVec3& a, const FVec3& b)
{
	return (FVec3(a.x - b.x, a.y - b.y, a.z - b.z));
}
