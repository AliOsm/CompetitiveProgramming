#include <bits/stdc++.h>

using namespace std;

int const MAX = 1000001;
bitset<MAX> prime;
int n, k, primes[MAX], cnt;

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

	scanf("%d %d", &n, &k);

	int res = 0;
	for(int i = 0; i < cnt; ++i) {
		if(primes[i] > n)
			break;

		for(int j = 1; j < i; ++j)
			if(primes[j - 1] + primes[j] + 1 == primes[i]) {
				++res;
				break;
			}
	}

	if(res >= k)
		puts("YES");
	else
		puts("NO");

	return 0;
}
