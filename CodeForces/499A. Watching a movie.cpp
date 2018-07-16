#include <bits/stdc++.h>

using namespace std;

int n, x, l, r;

int main() {
  cin >> n >> x;
  int res = 0;
  for(int i = 0, cur = 1; i < n; ++i) {
    cin >> l >> r;
    while(cur + x <= l)
      cur += x;
    res += (r - cur + 1);
    cur = r + 1;
  }
  cout << res << endl;

  return 0;
}
