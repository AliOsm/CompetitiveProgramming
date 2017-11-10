#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int const N = 1e6 + 1;
int const MOD = 1e9 + 7;
int n, a, b, d, fact[N], ifact[N];

int fst(int b, int p) {
  if(p == 0)
    return 1;
  
  int res = 1ll * fst(b, p >> 1) % MOD;
  res = 1ll * res * res % MOD;
  
  if(p & 1)
    res = 1ll * res * b % MOD;
  
  return res;
}

int nCk(int n, int k) {
  return 1ll * fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; ++i)
    fact[i] = 1ll * fact[i - 1] * i % MOD, ifact[i] = fst(fact[i], MOD - 2);
  
  while(scanf("%d %d %d %d", &n, &a, &b, &d) != EOF) {
    printf("%d\n", 1ll * nCk(n, a) * fst(nCk(b, d), a) % MOD);
  }
  
  return 0;
}
