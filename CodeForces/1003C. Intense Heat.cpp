#include <bits/stdc++.h>

using namespace std;

int const N = 5001;
int n, k, a[N], cs[N];

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  for(int i = 1; i <= n; ++i)
    cs[i] = cs[i - 1] + a[i - 1];

  long double res = 0, mul = 1.0;
  for(int i = 1; i <= n; ++i)
    for(int j = i; j <= n; ++j) {
      if(j - i + 1 < k)
        continue;

      res = max(res, mul * (cs[j] - cs[i - 1]) / (j - i + 1));
    }

  cout << fixed << setprecision(15) << res << endl;

  return 0;
}
