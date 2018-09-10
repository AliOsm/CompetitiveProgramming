/*
  Idea:
    - Simple math.
*/

#include <bits/stdc++.h>

using namespace std;

long long n, q, x, y, o, e, oo, ee;

int main() {
  scanf("%lld %lld", &n, &q);

  if(n % 2 == 0)
    o = e = n / 2;
  else
    o = n / 2 + 1, e = n / 2;

  while(q-- != 0) {
    scanf("%lld %lld", &x, &y);
    long long bf = 0;

    if((x + y) % 2 == 0)
      oo = o, ee = e;
    else
      oo = e, ee = o;

    long long xb = x - 1;
    if(xb % 2 == 0)
      bf = xb / 2 * oo + xb / 2 * ee;
    else
      bf = (xb / 2 + 1) * oo + xb / 2 * ee;

    long long yb = y - 1;
    bf += yb / 2;

    if((x + y) % 2 == 0)
      printf("%lld\n", bf + 1);
    else
      printf("%lld\n", ((1ll * n * n + 1) / 2) + 1 + bf);
  }

  return 0;
}
