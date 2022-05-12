#include "vector3.h"

struct matrix3x3
{
private:
	float n[3][3];

public:
	matrix3x3() = default;

	matrix3x3(	float n00, float n01, float n02,
				float n10, float n11, float n12,
				float n20, float n21, float n22)
	{
		n[0][0] = n00;
		n[0][1] = n01;
		n[0][2] = n02;
		n[1][0] = n10;
		n[1][1] = n11;
		n[1][2] = n12;
		n[2][0] = n20;
		n[2][1] = n21;
		n[2][2] = n22;
	}

	matrix3x3(const FVec3& a, const FVec3& b, const FVec3& c)
	{
		n[0][0] = a.x;
		n[0][1] = a.y;
		n[0][2] = a.z;

		n[1][0] = b.x;
		n[1][1] = b.y;
		n[1][2] = b.z;

		n[2][0] = c.x;
		n[2][1] = c.y;
		n[2][2] = c.z;
	}

	float& operator ()(int i, int j)
	{
		return (n[j][i]);
	}

	const float& operator () (int i, int j) const
	{
		return (n[j][i]);
	}

	FVec3& operator [] (int j)
	{
		return (*reinterpret_cast<FVec3 *>(n[j]));
	}

	const FVec3& operator [] (int j) const
	{
		return (*reinterpret_cast<const FVec3 *>(n[j]));
	}
};