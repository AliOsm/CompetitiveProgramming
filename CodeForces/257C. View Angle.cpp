/*
  Idea:
    - Calculate the angel between each point and the positive x-axis.
    - Then the answer will be the minimum angles[i] - angles[i-1].
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
long double const PI = acos(-1);
int n, gcd, a[N], b[N];
long double angs[N];

int main() {
  // third quarter +360
  // forth quarter +360
  // negative y-axis +360

  cin >> n;
  for(int i = 0; i < n; ++i) {
  	cin >> a[i] >> b[i];
  	angs[i] = atan2(b[i], a[i]) * 180 / PI;

  	if(a[i] == 0 && b[i] < 0 || a[i] < 0 && b[i] < 0 || a[i] > 0 && b[i] < 0)
  		angs[i] += 360;
  }

  sort(angs, angs + n);

  long double res = 361;
  for(int i = 1; i < n; ++i)
  	res = min(res, 360 - (angs[i] - angs[i - 1]));
  res = min(res, (angs[n - 1] - angs[0]));

  cout << fixed << setprecision(10) << res << endl;

  return 0;
}
