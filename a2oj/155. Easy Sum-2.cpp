#include <bits/stdc++.h>

using namespace std;

int const MOD = 33554431;
int t, n;

int power(int b, int p) {
  if(p == 1)
    return b;
  
  int ret = power(b, p >> 1);
  ret = 1ll * ret * ret % MOD;
  if(p & 1)
    ret = 1ll * ret * b % MOD;
  return ret;
}

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d", &n);
    printf("%d\n", (1ll * power(2, n) * 2 - 1) % MOD);
  }
  
  return 0;
}
