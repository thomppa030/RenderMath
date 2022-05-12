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

  /*
   * Overload the bracket operator to allow access to the Components
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
  TVec3<T> &operator*=(TVec3<T> &v) {
    return TVec3<T>{this.x * v.x, this.y * v.y, this.z * v.z};
  }

  /**
   * @brief Divides One over a Scalar vector and then multiplies every Element
   * with that value, returns a copy of the result
   *
   * @param s The Scalar Value to Divide over
   * @return A Copy of the resulting Vector
   */
  TVec3<T> operator/ (float s) {
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
   * @brief Returns the Length of the provided Vector
   * 
   * @param v The vector to retrieve the length of
   * @return The Length
   */
  float Magnitude(TVec3<T>& v) {
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
  }

  /**
   * @brief Returns a normalized version of the supplied Vector
   * 
   * @return A Normalized version of the supplied vector
   */
  TVec3<T> Normalize(TVec3<T> v) { return (v / Magnitude(v)); }

  void toString(TVec3<T> v)
  {
    printf_s("{%f %f %f}\n",v.x,v.y,v.z);
  }
};

typedef TVec3<float> FVec3;
typedef TVec3<int> IVec3;
typedef TVec3<unsigned int> UVec3;
