#include <bits/stdc++.h>

using namespace std;

int const N = 1000001;
int t, n;
bool prime[N];
vector<int> primes;

void sieve() {
  memset(prime, true, sizeof prime);
  prime[0] = prime[1] = false;
  for(int i = 2; i * i <= N; ++i)
    if(prime[i])
      for(int j = i * i; j <= N; j += i)
        prime[j] = false;
  for(int i = 0; i <= N; ++i)
    if(prime[i])
      primes.push_back(i);
}

int fai(int x) {
  int ret = x;
  for(int i = 0; i < (int)primes.size() && primes[i] * primes[i] <= x; ++i) {
    if(x % primes[i] == 0)
      ret -= ret / primes[i];
    while(x % primes[i] == 0)
      x /= primes[i];
  }
  if(x != 1)
    ret -= ret / x;
  return ret;
}

int main() {
  sieve();
  
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d", &n);
    if(prime[n]) {
      printf("%d\n", n - 1);
      continue;
    }
    printf("%d\n", fai(n));
  }
  
  return 0;
}
