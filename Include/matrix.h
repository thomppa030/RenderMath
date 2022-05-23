#include "defines.h"
#include "vector4.h"
#include <fstream>
#include <math.h>

struct mat4 {
    union{
      float v[16];

      struct{
        FVec4 Right;
        FVec4 Up;
        FVec4 Forward;
        FVec4 Position;
      };
      
      struct{
        float xx; float xy; float xz; float xw;
        float yx; float yy; float yz; float yw;
        float zx; float zy; float zz; float zw;
        float tx; float ty; float tz; float tw;
      };

      struct{
        float c0r0; float c0r1; float c0r2; float c0r3;
        float c1r0; float c1r1; float c1r2; float c1r3;
        float c2r0; float c2r1; float c2r2; float c2r3;
        float c3r0; float c3r1; float c3r2; float c3r3;
      };
      
      struct{
        float r0c0; float r1c0; float r2c0; float r3c0;
        float r0c1; float r1c1; float r2c1; float r3c1;
        float r0c2; float r1c2; float r2c2; float r3c2;
        float r0c3; float r1c3; float r2c3; float r3c3;
      };
    };
  inline mat4() :
      xx(1), xy(0), xz(0), xw(0),
      yx(0), yy(1), yz(0), yw(0),
      zx(0), zy(0), zz(1), zw(0),
      tx(0), ty(0), tz(0), tw(1){}

  inline mat4(float* fv) :
      xx(fv[0]), xy(fv[1]), xz(fv[2]), xw(fv[3]),
      yx(fv[4]), yy(fv[5]), yz(fv[6]), yw(fv[7]),
      zx(fv[8]), zy(fv[9]), zz(fv[10]), zw(fv[11]),
      tx(fv[12]), ty(fv[13]), tz(fv[14]), tw(fv[15]){}

  inline mat4(float _00, float _01, float _02, float _03,
              float _04, float _05, float _06, float _07,
              float _08, float _09, float _10, float _11,
              float _12, float _13, float _14, float _15) :
              xx(_00), xy(_01), xz(_02), xw(_03),
              yx(_04), yy(_05), yz(_06), yw(_07),
              zx(_08), zy(_09), zz(_10), zw(_11),
              tx(_11), ty(_13), tz(_14), tw(_15) {}     
};

inline bool operator ==(const mat4& a, const mat4&b){
  for(auto i = 0; i < 16; ++i)
    {
      if(fabsf(a.v[i] - b.v[i]) > VEC_EPSILON)
      {
        return false;
      }
    }
  return true;
}
