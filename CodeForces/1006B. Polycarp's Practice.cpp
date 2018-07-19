/*
  Idea:
    - Find the `k` largest numbers in array `a`, then
      split the array using there indexes.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2001;
int n, k, a[N];
pair<int, int> p[N];
vector<int> all;

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i)
    cin >> a[i], p[i].first = a[i], p[i].second = i;
  
  sort(p, p + n);
  
  int res = 0;
  for(int i = n - 1, cnt = 0; cnt < k; --i, ++cnt) {
    res += p[i].first;
    all.push_back(p[i].second + 1);
  }
  sort(all.begin(), all.end());
  
  cout << res << endl;
  for(int i = 0, cur = 0; i < all.size(); ++i) {
    if(i)
      cout << ' ';
    cout << (all[i] - cur) + (i == all.size() - 1 ? n - all.back() : 0);
    cur = all[i];
  }
  cout << endl;

  return 0;
}
