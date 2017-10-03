#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, r1 = 0, r2 = 0, r3 = 0;
  scanf("%d %d", &a, &b);
  for(int i = 1; i <= 6; ++i)
    if(abs(a - i) < abs(b - i))
      ++r1;
    else if(abs(a - i) == abs(b - i))
      ++r2;
    else
      ++r3;
  
  printf("%d %d %d\n", r1, r2, r3);
  
  return 0;
}
