#include <bits/stdc++.h>
 
using namespace std;
 
int const MOD = 1e9 + 7;
int const N = 1e2 + 1;
int const X = 1e6 + 1;
int n, x, coins[N], dp[N][X];
 
int rec(int idx, int rem) {
  if (rem == 0) {
    return 1;
  }
 
  if (idx >= n || rem < 0) {
    return 0;
  }
 
  int &res = dp[idx][rem];
  if (res != -1) {
    return res;
  }
 
  res = (rec(idx + 1, rem) + rec(idx, rem - coins[idx])) % MOD;
 
  return res;
}
 
int main() {
  scanf("%d %d", &n, &x);
 
  for(int i = 0; i < n; ++i) {
    scanf("%d", coins + i);
  }
 
  memset(dp, -1, sizeof dp);
 
  printf("%d\n", rec(0, x));
 
  return 0;
}

