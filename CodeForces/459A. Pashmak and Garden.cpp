#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
  return sqrt(pow(abs(x1 - x2), 2.0) + pow(abs(y1 - y2), 2.0));
}

bool ok(int x) {
  return x >= -1000 && x <= 1000;
}

void check(int x1, int y1, int x2, int y2) {
  if(ok(x1) && ok(y1) && ok(x2) && ok(y2)) {
    printf("%d %d %d %d\n", x1, y1, x2, y2);
    exit(0);
  }
}

int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int d = dist(x1, y1, x2, y2);
  
  if(x1 == x2) {
    y3 = y1;
    y4 = y2;
    
    x3 = x1 + d;
    x4 = x2 + d;
    check(x3, y3, x4, y4);
    
    x3 = x1 - d;
    x4 = x2 - d;
    check(x3, y3, x4, y4);
    
    puts("-1");
  } else if(y1 == y2) {
    x3 = x1;
    x4 = x2;
    
    y3 = y1 + d;
    y4 = y2 + d;
    check(x3, y3, x4, y4);
    
    y3 = y1 - d;
    y4 = y2 - d;
    check(x3, y3, x4, y4);
    
    puts("-1");
  } else if(abs(x1 - x2) == abs(y1 - y2)) {
    d = abs(x1 - x2);
    
    if(y1 > y2) {
      x3 = x1;
      y3 = y1 - d;
      
      x4 = x2;
      y4 = y2 + d;
      check(x3, y3, x4, y4);
      
      puts("-1");
    } else if(y1 < y2) {
      x3 = x1;
      y3 = y1 + d;
      
      x4 = x2;
      y4 = y2 - d;
      check(x3, y3, x4, y4);
      
      puts("-1");
    }
  } else puts("-1");
  
  return 0;
}

