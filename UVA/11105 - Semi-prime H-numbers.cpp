#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 1e6 + 10;

bool prime[N], semi_prime[N];
int cum[N];
vector<int> primes;

void hSieve() {
  memset(prime, true, sizeof prime);
  prime[0] = prime[1] = false;
  
  for(int i = 0, cnt = 4 * i + 1; cnt < N; ++i, cnt = 4 * i + 1)
    if(prime[cnt])
      for(int j = cnt + cnt; j < N; j += cnt)
        prime[j] = false;
  
  for(int i = 0, cnt = 4 * i + 1; cnt < N; ++i, cnt = 4 * i + 1)
    if(prime[cnt])
      primes.push_back(cnt);
}

int main() {
  hSieve();
  
  for(int i = 0, cnt = 4 * i + 1; cnt < N; ++i, cnt = 4 * i + 1)
    if(!prime[cnt])
      for(int j = 0; j < primes.size() && primes[j] * primes[j] <= cnt; ++j)
        if(semi_prime[cnt] || (cnt % primes[j] == 0 && prime[cnt / primes[j]])) {
          semi_prime[cnt] = true;
          break;
        }
  
  for(int i = 1; i < N; ++i)
    cum[i] = cum[i - 1] + semi_prime[i - 1];
  
  int n;
  while(scanf("%d", &n) && n != 0)
    printf("%d %d\n", n, cum[n+1]);
  
  return 0;
}

