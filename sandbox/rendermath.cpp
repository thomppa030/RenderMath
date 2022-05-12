#include "rendermath.h"

#include <stdio.h>

int main(void) {
    FVec3 fv (3.f,2.f,1.f);
    UVec3 uv {2,3,4};
    IVec3 iv {2,3,4};

    fv *= 4;

    float ff {fv.Magnitude(fv)};
    float uf {uv.Magnitude(uv)};
    float fi {iv.Magnitude(iv)};


    fv = fv.Normalize(fv);
    uv = uv.Normalize(uv);
    iv = iv.Normalize(iv);

    printf_s("%f \n", ff);
    printf_s("%f \n", uf);
    printf_s("%f \n", fi);
    fv.toString(fv);
    uv.toString(uv);
    iv.toString(iv);
    return 0;
}
