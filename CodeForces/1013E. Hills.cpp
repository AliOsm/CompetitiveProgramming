/*
  Idea:
    - Dynamic programming.
    - We can start dynamic programming `k` times and in each
      step `i` we try either to make the current house higher
      than its neighbors and move to `i + 2` or leave it and
      move to `i + 1`.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 5e3 + 100;
int n, a[N];
int dp[N][N][2];

int rec(int idx, int rem, bool lst) {
  if(rem == 0)
    return 0;
  if(idx > n)
    return 1e9;

  int &ret = dp[idx][rem][lst];
  if(ret != -1)
    return ret;
  ret = rec(idx + 1, rem, 0);

  int add = 0;
  if(lst) {
    int tmp = a[idx - 1];
    if(a[idx - 1] >= a[idx - 2]) {
      tmp = a[idx - 1] - a[idx - 2] + 1;
      tmp = a[idx - 1] - tmp;
    }
    if(tmp >= a[idx])
      add = tmp - a[idx] + 1;
    if(a[idx + 1] >= a[idx])
      add += a[idx + 1] - a[idx] + 1;
    ret = min(ret, rec(idx + 2, rem - 1, 1) + add);
  } else {
    if(a[idx - 1] >= a[idx])
      add = a[idx - 1] - a[idx] + 1;
    if(a[idx + 1] >= a[idx])
      add += a[idx + 1] - a[idx] + 1;
    ret = min(ret, rec(idx + 2, rem - 1, 1) + add);
  }

  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  a[0] = -1e9;
  a[n + 1] = -1e9;

  memset(dp, -1, sizeof dp);
  for(int i = 1; i <= (n + 1) / 2; ++i)
    printf("%d ", rec(1, i, 0));
  puts("");

  return 0;
}
