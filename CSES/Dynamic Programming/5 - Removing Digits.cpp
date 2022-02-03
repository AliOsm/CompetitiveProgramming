#include <bits/stdc++.h>
 
using namespace std;
 
int const OO = 2e9;
int const N = 1e6 + 1;
int n, coins[N], dp[N];
 
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
 
  int tmp = rem;
  while(tmp != 0) {
    res = min(res, rec(rem - (tmp % 10)) + 1);
    tmp /= 10;
  }
 
  return res;
}
 
int main() {
  scanf("%d", &n);
 
  memset(dp, -1, sizeof dp);
 
  printf("%d\n", rec(n));
 
  return 0;
}

