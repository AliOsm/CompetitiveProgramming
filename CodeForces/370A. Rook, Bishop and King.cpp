#include <bits/stdc++.h>

using namespace std;

int x, y, xx, yy;

int main() {
  scanf("%d %d %d %d", &x, &y, &xx, &yy);

  if(x == xx || y == yy)
    printf("1 ");
  else
    printf("2 ");
  
  if((x + y) % 2 != (xx + yy) % 2)
    printf("0 ");
  else if(abs(x - xx) == abs(y - yy))
    printf("1 ");
  else
    printf("2 ");
  
  int k = abs(x - xx) + abs(y - yy);
  if(abs(x - xx) < abs(y - yy))
    k -= abs(x - xx);
  else
    k -= abs(y - yy);
  printf("%d\n", k);

  return 0;
}
