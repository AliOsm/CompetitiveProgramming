#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1, MOD = 1e9 + 7;
int t, k, a, b;
long long dp[N];

long long rec(int cur) {
  if(cur < 0)
    return 0;
  
  if(cur == 0)
    return 1;
  
  long long &ret = dp[cur];
  if(ret != -1)
    return ret;
  ret = 0;
  
  return ret = ((rec(cur - 1) % MOD) + (rec(cur - k) % MOD)) % MOD;
}

int main() {
  scanf("%d %d", &t, &k);
  
  memset(dp, -1, sizeof dp);
  for(int i = 1; i < N; ++i)
    rec(i);
  
  dp[0] = 0;
  for(int i = 1; i < N; ++i)
    dp[i] = (dp[i] + dp[i - 1]);
  
  for(int i = 0; i < t; ++i) {
    scanf("%d %d", &a, &b);
    printf("%lld\n", (dp[b] - dp[a - 1]) % MOD);
  }
  
  return 0;
}

