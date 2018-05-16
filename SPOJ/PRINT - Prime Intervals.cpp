#include <bits/stdc++.h>

using namespace std;

int const MAX = 50001;
bitset<MAX> prime;
int cnt, primes[MAX], t, n, m;
bitset<1000001> vis;

void sieve_of_eratosthenes() {
	prime.set();

	prime[0] = prime[1] = 0;
	for(int i = 4; i < MAX; i += 2)
		prime[i] = 0;

	for(int i = 3; i * i < MAX; i += 2)
		if(prime[i])
			for(int j = i * i; j < MAX; j += (i << 1))
				prime[j] = 0;

	for(int i = 0; i < MAX; ++i)
		if(prime[i])
			primes[cnt++] = i;
}

int main() {
	sieve_of_eratosthenes();

	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d %d", &n, &m);

		vis.set();
		for(int i = 0, st; i < cnt; ++i) {
			st = 1ll * ceil(1.0 * n / primes[i]) * primes[i];
			if(st > m)
				break;
			for(int j = st; j <= m; j += primes[i])
				if(j < MAX && !prime[j] || j >= MAX)
					vis[j - n] = 0;
		}

		for(int i = n; i <= m; ++i)
			if(i != 1 && vis[i - n] == 1)
				printf("%d\n", i);
	}

  return 0;
}
