#include "rendermath.h"

int main(void) {
  FVec3 fvl(3.2f, 2.1f, 1.f);

  fvl.toString();

  printf("Squarelength of the Vector is: %f \n", GetLengthSquare(fvl));
  printf("Length of the Vector is: %f \n", GetLength(fvl));
  fvl.toString();
  FVec3 temp = normalized(fvl);
  temp.toString();
  normalize(fvl);
  fvl.toString();
  return 0;
}
