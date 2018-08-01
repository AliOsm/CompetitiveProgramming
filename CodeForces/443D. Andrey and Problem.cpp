#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n;
double a[N];

int main() {
  double mx = 0;
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a, a + n);
  reverse(a, a + n);

  double res = 0;
  for(int k = 0; k < n; ++k) {
    double sol = 0;
    for(int i = 0; i <= k; ++i) {
      double cur = a[i];
      for(int j = 0; j <= k; ++j)
        if(i != j)
          cur *= (1.0 - a[j]);
      sol += cur;
    }
    res = max(res, sol);
  }

  cout << fixed << setprecision(10) << res << endl;

  return 0;
}
