#include "rendermath.h"
#include "config.hpp"

#include <stdio.h>

int main(void) {
    FVec3 fvl (3.2f,2.1f,1.f);
    FVec3 fvr (.2f,4.1f,1.f);
    UVec3 uv {2,3,4};
    IVec3 iv {2,3,4};

    FVec2 ftl {3.6f, 9.9f};
    FVec2 ftr {-3.6f, -9.9f};
    
    fvl.toString();

    fvl *= 4;

    float ff {Magnitude(fvl)};
    float uf {Magnitude(uv)};
    float fi {Magnitude(iv)};


    fvl = Normalize(fvl);
    uv = Normalize(uv);
    iv = Normalize(iv);

    float dotfv = dot(fvl,fvr);
    float dotftv = dot(ftl, ftr);

    printf_s("%f \n", ff);
    printf_s("%f \n", uf);
    printf_s("%f \n", fi);
    printf_s("%f \n", dotfv);
    printf_s("%f \n", dotftv);
    fvl.toString();
    uv.toString();
    iv.toString();

    std::cout << project_name << " " << project_version << std::endl;

    return 0;
}
