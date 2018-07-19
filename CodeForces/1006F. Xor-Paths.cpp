/*
  Idea:
    - Using meet in the middle technique we can generate all paths
      start at point `(0, 0)` and end in the middle of the grid with
      its result.
    - Then we can construct all paths start from point `(n-1, m-1)`
      and end in the middle of the grid and check how many numbers
      the XOR of them with the current result equal to `k`.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 21;
int n, m;
long long a[N][N], k, res;
vector<int> all[2];
map<pair<int, int>, map<long long, int> > mp;

void rec(int idx, int msk, int end, int r1, int r2, int cur) {
  if(r1 < 0 || r2 < 0)
    return;

  if(idx == end) {
    all[cur].push_back(msk);
    return;
  }

  rec(idx + 1, msk, end, r1 - 1, r2, cur);
  rec(idx + 1, msk | (1 << idx), end, r1, r2 - 1, cur);
}

void go(int i, int j, int di, int dj, int msk, int idx, int end, long long sum, bool ok) {
  if(idx == end) {
    if(!ok)
      ++mp[{i, j}][sum ^ a[i][j]];
    else
      res += mp[{i, j}][sum ^ k];

    return;
  }

  if(((msk >> idx) & 1) == 0)
    go(i + di, j, di, dj, msk, idx + 1, end, sum ^ a[i][j], ok);
  else
    go(i, j + dj, di, dj, msk, idx + 1, end, sum ^ a[i][j], ok);
}

int main() {
  scanf("%d %d %lld", &n, &m, &k);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      scanf("%lld", &a[i][j]);

  int spl = (n-1 + m-1) / 2;

  rec(0, 0, spl, n - 1, m - 1, 0);
  rec(0, 0, (n-1 + m-1) - spl, n - 1, m - 1, 1);

  for(int i = 0; i < all[0].size(); ++i)
    go(0, 0, 1, 1, all[0][i], 0, spl, 0, false);

  for(int i = 0; i < all[1].size(); ++i)
    go(n - 1, m - 1, -1, -1, all[1][i], 0, ((n-1 + m-1) - spl), 0, true);

  printf("%lld\n", res);

  return 0;
}
