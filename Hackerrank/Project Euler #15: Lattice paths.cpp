#include <bits/stdc++.h>

using namespace std;

int const N = 1001, MOD = 1000000007;
int t, n, m, fact[N], ifact[N];

int fast_power(const int &base, const int &power) {
  if(power == 0)
    return 1;

  if(power == 1)
    return base;

  int ret = fast_power(base, power / 2) % MOD;
  ret = 1ll * ret * ret % MOD;

  if(power % 2 == 1)
    ret = 1ll * ret * base % MOD;

  return ret;
}

int n_choose_k(const int &n, const int &k) {
  return 1ll * fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; ++i) {
    fact[i] = 1ll * fact[i - 1] * i % MOD;
    ifact[i] = fast_power(fact[i], MOD - 2);
  }

  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d %d", &n, &m);
    printf("%d\n", n_choose_k(n + m, n));
  }

  return 0;
}
