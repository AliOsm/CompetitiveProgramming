#include <bits/stdc++.h>

using namespace std;

int const MAX = 10001;
bitset<MAX> prime;
int n, primes[MAX], p;

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
			primes[p++] = i;
}

int main() {
	sieve_of_eratosthenes();

	while(scanf("%d", &n) != EOF) {
		printf("1");
		for(int i = 0; i < MAX && primes[i] * primes[i] <= n; ++i)
			while(n % primes[i] == 0) {
				printf(" x %d", primes[i]);
				n /= primes[i];
			}
		if(n != 1)
			printf(" x %d", n);
		puts("");
	}

	return 0;
}
