#include <bits/stdc++.h>
 
using namespace std;
 
int const OO = 2e9;
int const N = 1e2 + 1;
int const X = 1e6 + 1;
int n, x, coins[N], dp[X];
 
int rec(int rem) {
  if (rem == 0) {
    return 0;
  }
 
  if (rem < 0) {
    return OO;
  }
 
  int &res = dp[rem];
  if (res != -1) {
    return res;
  }
 
  res = OO;
  for(int i = 0; i < n; ++i) {
    res = min(res, rec(rem - coins[i]) + 1);
  }
 
  return res;
}
 
int main() {
  scanf("%d %d", &n, &x);
 
  for(int i = 0; i < n; ++i) {
    scanf("%d", coins + i);
  }
 
  memset(dp, -1, sizeof dp);
 
  int res = rec(x);
 
  if (res == OO) {
    puts("-1");
  } else {
    printf("%d\n", res);
  }
 
  return 0;
}

