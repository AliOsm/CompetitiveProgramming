#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, w, a[1001];

int main() {
  cin >> n >> w;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  long long to = 0, mn = 1e18, mx = -1e18;
  for(int i = 0; i < n; ++i) {
    to += a[i];
    mn = min(mn, to);
    mx = max(mx, to);
  }

  mn = min(mn, 0ll);
  mx = max(mx, 0ll);

  if((w - mx) + mn + 1 < 0)
    cout << 0 << endl;
  else
    cout << (w - mx) + mn + 1 << endl;

  return 0;
}
