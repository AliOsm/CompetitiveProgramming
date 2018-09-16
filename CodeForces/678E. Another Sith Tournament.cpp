/*
  Idea:
    - Dynamic Programming.
    - Because Jedi can choose who is the first person and the next
      one in each battle, then we can do a DP and in each step
      take the maximum between the two returned values.
*/

#include <bits/stdc++.h>

using namespace std;

int n;
double p[18][18], dp[18][(1 << 18)];

double rec(int lst, int msk) {
  if(__builtin_popcount(msk) == n - 1)
    return lst == 0;

  double &ret = dp[lst][msk];
  if(ret == ret)
    return ret;
  ret = 0;

  double cur;
  for(int i = 0; i < n; ++i)
    if(i != lst && ((msk >> i) & 1) == 0) {
      cur = 0;
      cur += p[lst][i] * rec(lst, msk | (1 << i));
      cur += p[i][lst] * rec(i, msk | (1 << lst));
      ret = max(ret, cur);
    }

  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      scanf("%lf", &p[i][j]);

  memset(dp, -1, sizeof dp);
  double res = 0;
  for(int i = 0; i < n; ++i)
    res = max(res, rec(i, 0));

  printf("%0.10lf\n", res);

  return 0;
}
