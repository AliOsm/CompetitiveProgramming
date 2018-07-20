#include <bits/stdc++.h>

using namespace std;

int const N = 5e3 + 1, MOD = 1e9 + 7;
int n, a, b, k, dp[N][N];

int main() {
  cin >> n >> a >> b >> k;

  if(a > b) {
    b = n - b + 1;
    a = n - a + 1;
  }
  n = b - 1;

  dp[a][0] = 1;

  for(int j = 1, mx; j <= k; ++j) {
    for(int i = 1; i <= n; ++i)
      dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;

    for(int i = 1; i <= n; ++i) {
      mx = (b + i) / 2 - ((b + i) % 2 == 0);
      dp[i][j] = (dp[i - 1][j - 1] % MOD + ((dp[mx][j - 1] - dp[i][j - 1]) + MOD) % MOD) % MOD;
    }
  }

  int res = 0;
  for(int i = 1; i <= n; ++i)
    res = (res + dp[i][k]) % MOD;

  cout << res << endl;

  return 0;
}
