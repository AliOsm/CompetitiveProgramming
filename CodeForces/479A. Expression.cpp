#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  
  int res = 0;
  
  res = max(res, a + b * c);
  res = max(res, a * b + c);
  res = max(res, (a + b) * c);
  res = max(res, a * (b + c));
  res = max(res, a + b + c);
  res = max(res, a * b * c);
  
  printf("%d\n", res);
  
  return 0;
}

