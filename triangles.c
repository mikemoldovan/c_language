#include <stdio.h>

int triang_type(double sq1,double sq2,double sq3) {
  if (sq1+sq2 > sq3 && sq1+sq3 > sq2 && sq2+sq3 > sq1) {
    return 1;
  }
  if (sq1+sq2 == sq3 || sq1+sq3 == sq2 || sq2+sq3 == sq1) {
    return 3;
  }
  if (sq1+sq2 < sq3 || sq1+sq3 < sq2 || sq2+sq3 < sq1) {
    return 2;
  }
  return 0;
}

int main(){
  double x;
  double y;
  double z;
  scanf("%lf",&x);
  scanf("%lf",&y);
  scanf("%lf",&z);
  if (x + y == z || x + z == y || y + z == x) {
    printf("degenerate\n");
    return 0;
  } else {
    int type;
    type = triang_type(x*x,y*y,z*z);
//    printf("%lf, %lf, %lf\n", x*x,y*y,z*z);
    if (type == 1) {printf("acute\n");}
    if (type == 2) {printf("obtuse\n");}
    if (type == 3) {printf("right\n");}
    return 0;
  }
}
