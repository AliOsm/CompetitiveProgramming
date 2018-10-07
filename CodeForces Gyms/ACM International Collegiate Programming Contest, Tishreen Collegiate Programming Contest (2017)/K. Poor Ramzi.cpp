#include <bits/stdc++.h>

using namespace std;

int const N = 51, MOD = 1e9 + 7;
int t, cs[N], len, dp[N][N];
char s[N];

int rec(int i, int j) {
  if(i >= j)
    return 1;

  int &ret = dp[i][j];
  if(ret != -1)
    return ret;
  ret = 1;

  for(int ii = i, c1; ii < j; ++ii) {
    c1 = cs[ii] - cs[i - 1];
    for(int jj = j, c2; jj > ii; --jj) {
      c2 = cs[j] - cs[jj - 1];
      if(c1 == c2)
        ret = (ret + rec(ii + 1, jj - 1)) % MOD;
    }
  }

  return ret;
}

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    len = strlen(s);
    for(int i = 1; i <= len; ++i)
      cs[i] = cs[i - 1] + (s[i - 1] - '0');

    memset(dp, -1, sizeof dp);
    printf("%d\n", rec(1, len));
  }

  return 0;
}
