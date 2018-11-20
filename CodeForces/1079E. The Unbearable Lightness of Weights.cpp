/*
  Idea:
    - If there is only two types of masses, then we can
      determine the `n` weights.
    - Otherwise, we should pick one type of the masses
      and select some weights from it, but we should
      check that there is only one subset have this
      weight sum and contains exactly `k` elements.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, a[N], fr[N];
short dp[N][N][N*N];

short rec(int idx, int rem, int sum) {
  if(rem < 0 || sum < 0)
    return 0;
  if(idx == N)
    return rem == 0 && sum == 0;

  short &ret = dp[idx][rem][sum];
  if(ret != -1)
    return ret;
  ret = min(2, int(rec(idx + 1, rem, sum)));

  for(int i = 1; i <= fr[idx]; ++i)
    ret = min(2, ret + rec(idx + 1, rem - i, sum - idx * i));

  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), ++fr[a[i]];

  int cnt = 0;
  for(int i = 0; i < N; ++i)
    cnt += fr[i] != 0;

  if(cnt <= 2) {
    printf("%d\n", n);
    return 0;
  }

  memset(dp, -1, sizeof dp);
  int res = 0;
  for(int i = 1; i < N; ++i)
    for(int j = 1; j <= fr[i]; ++j)
      if(rec(1, j, i * j) == 1)
        res = max(res, j);
  printf("%d\n", res);

  return 0;
}
