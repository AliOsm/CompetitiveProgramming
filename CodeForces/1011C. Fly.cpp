/*
  Idea:
    - Binay search on the minimum value you can add to `m`
      to travel over all planets and go back to Earth.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 10;
int n, m, a[N], b[N];

bool can(long double mid) {
  long double cur = 1.0 * m + mid;
  for(int i = 0; i < n; ++i) {
    cur -= 1.0 * cur / a[i];
    cur -= 1.0 * cur / b[i + 1];
  }
  return cur >= 1.0 * m;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0; i < n; ++i)
    scanf("%d", b + i);
  a[n] = a[0];
  b[n] = b[0];

  double sol = 2e18;

  long double l = 1, r = 1e18, mid, res = -1;
  for(int i = 0; i < 100; ++i) {
    mid = (l + r) / 2.0;
    if(can(mid))
      res = mid, r = mid;
    else
      l = mid;
  }

  cout << fixed << setprecision(10) << res << endl;

  return 0;
}
