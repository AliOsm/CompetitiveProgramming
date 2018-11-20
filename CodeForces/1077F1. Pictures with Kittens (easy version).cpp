/*
  Idea:
    - Dynamic Programming
    - dp[idx][prv][rem] represents:
      idx: the current index
      prv: how many elements discarded before
      rem: the remaining elements to take
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e2 + 1;
int n, k, x, a[N];
long long dp[N][N][N];

long long rec(int idx, int prv, int rem) {
  if(rem < 0 || prv >= k)
    return -1e15;
  if(idx == n)
    return rem == 0 ? 0 : -1e15;

  long long &ret = dp[idx][prv][rem];
  if(ret != -1)
    return ret;
  ret = -1e15;

  ret = max(ret, rec(idx + 1, prv + 1, rem));
  ret = max(ret, rec(idx + 1, 0, rem - 1) + a[idx]);

  return ret;
}

int main() {
  scanf("%d %d %d", &n, &k, &x);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  memset(dp, -1, sizeof dp);
  long long res = rec(0, 0, x);

  if(res <= 0)
    puts("-1");
  else
    printf("%lld\n", res);

  return 0;
}
