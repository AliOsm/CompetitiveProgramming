#include <bits/stdc++.h>

using namespace std;

int const MOD = 1000000007;
long long n;

long long power(int b, long long p) {
  if(p == 0)
    return 1;
  
  long long res = power(b, p >> 1);
  res = res * res % MOD;
  if(p & 1)
    res = res * b % MOD;
  return res;
}

int main() {
  scanf("%lld", &n);
  long long r = power(2, n);
  printf("%lld\n", (r * (r + 1) / 2) % MOD);
  
  return 0;
}
