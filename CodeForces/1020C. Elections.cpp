/*
  Idea:
    - Brute force.
    - Try to make all parties voters less than `i` where `i`
      from 1 to `n`.
    - We can do this in two steps, in the first step we buy all
      cheap voters in each party have move than or `i` voters,
      then in the second step if we do not reach `i` voters for
      our party we buy the cheapest voters overall.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> all;
vector<vector<int> > g;

long long calc(int mx) {
  long long ret = 0, take = g[0].size();

  all.clear();
  for(int i = 1, size; i < m; ++i) {
    size = max(0, int(g[i].size()) - mx + 1);
    for(int j = 0; j < size; ++j)
      ret += g[i][j], ++take;
    for(int j = size; j < g[i].size(); ++j)
      all.push_back(g[i][j]);
  }

  sort(all.begin(), all.end());

  for(int i = 0; i < all.size() && take < mx; ++i)
    ret += all[i], ++take;

  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  g.resize(m);
  for(int i = 0, a, b; i < n; ++i) {
    scanf("%d %d", &a, &b);
    --a;
    g[a].push_back(b);
  }

  for(int i = 0; i < m; ++i)
    sort(g[i].begin(), g[i].end());

  long long res = 1e18;
  for(int i = 1; i <= n; ++i)
    res = min(res, calc(i));

  printf("%lld\n", res);

  return 0;
}
