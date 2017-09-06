#include <bits/stdc++.h>

using namespace std;

int n, l, r, x, a[16];

int rec(int at, int sm, int ct, int lw, int hi) {
  if(at == n)
    return sm >= l && sm <= r && ct >= 2 && hi - lw >= x;
  
  int r1 = rec(at + 1, sm, ct, lw, hi);
  int r2 = rec(at + 1, sm + a[at], ct + 1, min(lw, a[at]), max(hi, a[at]));
  return r1 + r2;
}

int main() {
  scanf("%d %d %d %d", &n, &l, &r, &x);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  
  printf("%d\n", rec(0, 0, 0, 1e9, -1e9));
  
  return 0;
}
