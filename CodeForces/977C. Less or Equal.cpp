#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;
vector<pair<int, int> > all;

int main() {
  cin >> n >> k;
  a.resize(n);
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a.begin(), a.end());

  if(k == 0) {
    if(a[0] != 1)
      cout << 1 << endl;
    else
      cout << -1 << endl;
    return 0;
  }

  for(int i = 0, j, cur; i < n; ++i) {
    j = i;
    cur = a[i];
    while(i < n && a[i] == cur)
      ++i;
    --i;

    all.push_back({i - j + 1, cur});
  }

  for(int i = 0; i < all.size(); ++i) {
    k -= all[i].first;

    if(k == 0) {
      cout << all[i].second << endl;
      return 0;
    }

    if(k < 0)
      break;
  }

  cout << -1 << endl;

  return 0;
}
