#include <bits/stdc++.h>

using namespace std;

int n, u, a[100001], nxt[100001];

int main() {
  cin >> n >> u;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  int cur = n - 1;
  for(int i = n - 1; i >= 0; --i) {
    while(a[cur] - a[i] > u)
      --cur;
    nxt[i] = cur;
  }

  double best = -1;
  for(int i = 0; i < n - 1; ++i) {
    int idx = nxt[i];
    if(a[idx] - a[i] > u || idx - i + 1 < 3)
      continue;

    best = max(best, 1.0 * (a[idx] - a[i + 1]) / (a[idx] - a[i]));
  }

  cout << fixed << setprecision(10) << best << endl;

  return 0;
}
