#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, m;
long long a[N], cs[N];

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  cs[0] = 0;
  for(int i = 1; i <= n; ++i)
    cs[i] = cs[i - 1] + a[i - 1];

  long long tmp;
  for(int i = 0; i < m; ++i) {
    cin >> tmp;
    int idx = lower_bound(cs, cs + n + 1, tmp) - cs;

    cout << idx << ' ';
    tmp -= cs[idx - 1];
    cout << tmp << endl;
  }

  return 0;
}
