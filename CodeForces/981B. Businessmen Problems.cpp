/*
  Idea:
    - Greedy, for each value in each company choose the largest one.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m;
map<int, int> a, b;
vector<int> all;

int main() {
  scanf("%d", &n);
  for(int i = 0, x, y; i < n; ++i) {
  	scanf("%d %d", &x, &y);
  	a[x] = y;
  	all.push_back(x);
  }

	scanf("%d", &m);
  for(int i = 0, x, y; i < m; ++i) {
  	scanf("%d %d", &x, &y);
  	b[x] = y;
  	all.push_back(x);
  }

  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());

  long long res = 0;
  for(int i = 0, mx; i < all.size(); ++i) {
  	mx = 0;
  	if(a.count(all[i]))
  		mx = max(mx, a[all[i]]);
  	if(b.count(all[i]))
  		mx = max(mx, b[all[i]]);
  	res += mx;
  }

  printf("%lld\n", res);

  return 0;
}
