#include "defines.h"
#include "math.h"

// TODO: Make Define Header for RenderMath
template <typename T> struct TVec3 {
  union {
    struct {
      T x;
      T y;
      T z;
    };
    T v[3];
  };

  inline TVec3<T>() : x((T)0), y((T)0), z((T)0){};

  inline TVec3<T>(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

  /**
   * @brief Overload the bracket operator to allow access to the Components
   *
   * @param i The index to be accessed
   * @return * Overload&
   */
  T &operator[](int i) { return ((&x)[i]); }

  const T &operator[](int i) const { return ((&x)[i]); }

  /**
   * @brief Multiplies the All Elements within the vector with a Scalar Value
   * and returns a copy of the result
   *
   * @param s Scalar Value to multiply with
   * @return A copy of the resulting vector
   */
  TVec3<T> &operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;

    return (*this);
  }
  /**
   * @brief Multiplies the Vector by Another Vector and returns a copy of the
   * result
   *
   * @param v The vector3 to multiply with
   * @return A copy of the resulting vector
   */

  /**
   * @brief Divides One over a Scalar vector and then multiplies every Element
   * with that value, returns a copy of the result
   *
   * @param s The Scalar Value to Divide over
   * @return A Copy of the resulting Vector
   */
  TVec3<T> operator/(float s) {
    s = 1.0f / s;
    x *= s;
    y *= s;
    z *= s;
    return (*this);
  }

  TVec3<T> &operator/=(float s) {
    s = 1.0f / s;
    x *= s;
    y *= s;
    z *= s;
    return (*this);
  }

  /**
   * @brief Adds Two Vectors together and returns a copy of the result
   *
   * @param v The Vector3 to add
   * @return A Copy of the result
   */
  TVec3<T> &operator+=(const TVec3<T> &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return (*this);
  }

  /**
   * @brief Subtracts a Vector from the origin Vector and returns a copy of the
   * result
   *
   * @param v The Vector to subtract with
   * @return A Copy of the result
   */
  TVec3<T> &operator-=(const TVec3<T> &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return (*this);
  }

  /**
   * @brief Prints out the Elements of the Vector
   *
   */
  void toString() {
    std::cout << "{" << x << " " << y << " " << z << "}" << std::endl;
  }
};

typedef TVec3<float> FVec3;
typedef TVec3<int> IVec3;
typedef TVec3<unsigned int> UVec3;

/**
 * @brief Returns the Length of the provided Vector
 *
 * @param v The vector to retrieve the length of
 * @return The Length
 */
template <typename T> inline float Magnitude(TVec3<T> v) {
  return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

/**
 * @brief Returns the Dot Product of Two Vectors
 * - If positive the vectors point in the same direction
 * - If negative the vectors point in the opposite direction
 * - If Zero the vectors are perpendicular
 *
 * @tparam T VectorType
 * @param l Vector 1
 * @param r Vector 2
 * @return returns the dot Product of two Vectors
 */
template <typename T> inline float dot(const TVec3<T> &l, const TVec3<T> &r) {
  return l.x * r.x + l.y * r.y + l.z * r.z;
}

/**
 * @brief Get the square length of a Vector
 *
 * @param v The Vector to get the length of
 * @return the square length of the given Vector
 */
template <typename T> inline float GetLengthSquare(const TVec3<T> &v) {
  return v.x * v.x + v.y * v.y + v.z * v.z;
}

/**
 * @brief      returns the Length of a given Vector
 *
 * @param      v     The vector to calculate the length of
 *
 * @tparam     T     { description }
 *
 * @return     the length of the given Vector
 */
template <typename T> inline float GetLength(const TVec3<T> &v) {
  float sqLen = v.x * v.x + v.y * v.y + v.z * v.z;
  if (sqLen < VEC_EPSILON) {
    return 0.0f;
  }
  return sqrtf(sqLen);
}

/**
 * @brief Returns a normalized version of the supplied Vector
 *
 * @return A Normalized version of the supplied vector
 */
template <typename T> inline void normalize(TVec3<T> &v) {
  float lenSq = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
  if (lenSq < VEC_EPSILON) {
    return;
  }
  float invLen = 1.0f / sqrtf(lenSq);
  v.x *= invLen;
  v.y *= invLen;
  v.z *= invLen;
}

/**
 * @brief Returns a normalized Vector
 *
 * @param v a Vector to get a normalize
 * @return returns a copy of the normalized Vector
 */
template <typename T> inline TVec3<T> normalized(const TVec3<T> &v) {
  float lenSq = GetLengthSquare(v);
  if (lenSq < VEC_EPSILON) {
    return v;
  }
  float invLength = 1.0f / sqrtf(lenSq);
  return TVec3<T>(v.x * invLength, v.y * invLength, v.z * invLength);
}
