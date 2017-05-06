#include <stdio.h>

int main() {
  double h, u, d, f, tmp;
  int day;
  
  while(scanf("%lf%lf%lf%lf", &h, &u, &d, &f) && h != 0) {
    tmp = 0, day = 1;
    f /= 100.0;
    f *= u;
    
    while(true) {
      if(u > 0)
        tmp += u;
      
      if(tmp - 1e-9 >= h) {
        printf("success on day %d\n", day);
        break;
      }
      
      tmp -= d;
      
      if(tmp + 1e-9 < 0) {
        printf("failure on day %d\n", day);
        break;
      }
      
      u -= f;
      
      ++day;
    }
  }
  
  return 0;
}

