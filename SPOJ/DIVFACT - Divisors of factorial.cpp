#include <bits/stdc++.h>

using namespace std;

int const N = 50001, MOD = 1000000007;
int t, n, res, powers[N];
bool prime[N];
vector<int> primes;
vector<vector<pair<int, int> > > facts;

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

void calc() {
  facts.resize(N);
  for(int i = 2; i <= N; ++i) {
    // cout << "CUR: " << i << endl;
    int cur = i, cnt;
    for(int j = 0; j < (int)primes.size() && primes[j] * primes[j] <= cur; ++j) {
      // cout << "PRIME: " << primes[j] << endl;
      cnt = 0;
      while(cur % primes[j] == 0) {
        cur /= primes[j];
        ++cnt;
      }
      if(cnt)
        facts[i].push_back(make_pair(primes[j], cnt));
    }
    if(cur != 1)
      facts[i].push_back(make_pair(cur, 1));
  }
}

int main() {
  sieve();
  calc();
  
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d", &n);
    memset(powers, 0, sizeof powers);
    for(int i = 2; i <= n; ++i)
      for(int j = 0; j < (int)facts[i].size(); ++j)
        powers[facts[i][j].first] += facts[i][j].second;
    res = 1;
    for(int i = 2; i <= n; ++i)
      res = (1ll * res * (powers[i] + 1)) % MOD;
    printf("%d\n", res);
  }
  
  return 0;
}
