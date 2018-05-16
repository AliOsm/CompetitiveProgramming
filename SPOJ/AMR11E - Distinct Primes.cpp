#include <bits/stdc++.h>

using namespace std;

int const MAX = 100001;
bitset<MAX> prime;
int lookup[MAX], t, n;
vector<int> all;

void sieve_of_eratosthenes() {
	prime.set();

	prime[0] = prime[1] = 0;
	for(int i = 2; i < MAX; ++i)
		if(prime[i])
			for(long long j = 1ll * i * 2; j < MAX; j += i)
				++lookup[j], prime[j] = 0;
}

int main() {
	sieve_of_eratosthenes();
	
	for(int i = 0; i < MAX; ++i)
		if(lookup[i] >= 3)
			all.push_back(i);

	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d", &n);
		printf("%d\n", all[n-1]);
	}

	return 0;
}
