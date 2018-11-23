/*
  Idea:
    - Precalculate the cost to fix the interval (i, j).
    - Using Dynamic Programming we can solve the problem
      of choosing `k` points in not intersected ranges
      with minimum value.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 3e2 + 1;
long long oo = 1e16;
int n, m, k;
long long cost[N][N], dp[N][N];

long long rec(int idx, int rem) {
  if(rem <= 0)
    return 0;

  if(idx > n)
    return oo;

  long long &ret = dp[idx][rem];
  if(ret != -1)
    return ret;
  ret = oo;

  ret = min(ret, rec(idx + 1, rem));
  for(int i = idx; i <= n; ++i)
    ret = min(ret, rec(i + 1, rem - (i - idx + 1)) + cost[idx][i]);

  return ret;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);

  for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= n; ++j)
      cost[i][j] = oo;

  for(int i = 0, l, r, c; i < m; ++i) {
    scanf("%d %d %d", &l, &r, &c);
    for(int j = l; j <= r; ++j)
      cost[l][j] = min(cost[l][j], 1ll * c);
  }

  memset(dp, -1, sizeof dp);
  if(rec(1, k) < oo)
    printf("%lld\n", rec(1, k));
  else
    puts("-1");

  return 0;
}
