#include <stdio.h>

int main () {
  long long a, b, c, d, e, f, centroa, centrob, tempat;

  scanf ("[%lld,%lld] | [%lld,%lld] | [%lld,%lld]", &a, &d, &b, &e, &c, &f);
    
  // centro nya
  centroa = (a + b + c)/3;
  centrob = (d + e + f)/3;
  
  tempat = 0.5 * (a * (e - f) + b * (f - d) + c * (d - e));
  //rumus luas segitiga dari tiga titik 

  //limit 
  if (a >= 0 && b >= 0 && c>= 0 && a <= 1000000000 && b <= 1000000000 && c <= 1000000000) {
    
    // lewati yang overlap
    if (((a == b) && (d == e)) || ((b == c) && (e == f)) || ((a == c) && (d == f))) {
      printf("Henshin! Entry.");
    }
    else {
      if (tempat == 0) {
        if (centroa % 2 != 0 && centrob % 2 != 0) {
          printf("Boost Raise Buckle Acquired at Coordinate [%lld,%lld]\nHenshin! Boost, Ready, Fight!", centroa, centrob);
        }
        else {
          printf("Henshin! Entry.");
        }
      }
      else {
        if (centroa % 2 == 0 && centrob % 2 == 0) {
          printf("Magnum Raise Buckle Acquired at Coordinate [%lld,%lld]\nHenshin! Magnum, Ready, Fight!", centroa, centrob);
        }
        else {
          printf("Henshin! Entry.");
        }
      }
    }
  }
}