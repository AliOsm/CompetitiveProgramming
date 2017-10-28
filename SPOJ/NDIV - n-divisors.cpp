#include <bits/stdc++.h>

using namespace std;

int const N = 2000001;
int a, b, n, res, sol;
bool prime[N];
vector<int> primes, facts;

void sieve() {
  memset(prime, true, sizeof prime);
  prime[0] = prime[1] = false;
  for(int i = 2; i * i <= N; ++i)
    if(prime[i])
      for(int j = i * i; j <= N; j += i)
        prime[j] = false;
  for(int i = 0; i < N; ++i)
    if(prime[i])
      primes.push_back(i);
}

void fact(int x) {
  facts.clear();
  for(int i = 0, cnt; i < (int)primes.size() && primes[i] * primes[i] <= x; ++i) {
    cnt = 0;
    while(x % primes[i] == 0)
      x /= primes[i], ++cnt;
    if(cnt)
      facts.push_back(cnt);
  }
  if(x != 1)
    facts.push_back(1);
}

int main() {
  sieve();
  sol = 0;
  scanf("%d %d %d", &a, &b, &n);
  for(int i = a; i <= b; ++i) {
    fact(i);
    res = 1;
    for(int j = 0; j < (int)facts.size(); ++j)
      res = res * (facts[j] + 1);
    if(res == n)
      ++sol;
  }
  printf("%d\n", sol);
  
  return 0;
}
