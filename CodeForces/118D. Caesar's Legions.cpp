#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1, MOD = 1e8;
int n1, n2, k1, k2, dp[N][N][11][11];

int rec(int r1, int r2, int l1, int l2) {
  if(r1 > n1 || r2 > n2 || l1 > k1 || l2 > k2)
    return 0;
  
  if(r1 == n1 && r2 == n2)
    return 1;
  
  int &ret = dp[r1][r2][l1][l2];
  if(ret != -1)
    return ret;
  ret = 0;
  
  ret = ret + rec(r1 + 1, r2, l1 + 1, 0) % MOD;
  ret = ret + rec(r1, r2 + 1, 0, l2 + 1) % MOD;
  
  return ret;
}

int main() {
  scanf("%d %d %d %d", &n1, &n2, &k1, &k2);

  memset(dp, -1, sizeof dp);  
  cout << rec(0, 0, 0, 0) % MOD << endl;
  
  return 0;
}
