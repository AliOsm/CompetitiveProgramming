#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> all;
int const MAX = 20000001;
bitset<MAX> prime;

void sieve_of_eratosthenes() {
	prime.set();

	prime[0] = prime[1] = 0;
	for(int i = 4; i < MAX; i += 2)
		prime[i] = 0;

	for(int i = 3; i * i < MAX; i += 2)
		if(prime[i])
			for(int j = i * i; j < MAX; j += (i << 1))
				prime[j] = 0;
}

inline int toInt() {
	if(all[0] == 0)
		return 1;
	int ret = 0;
	for(int i = 0; i < all.size(); ++i) {
		ret *= 10;
		ret += all[i];
	}
	return ret;
}

int main() {
	sieve_of_eratosthenes();

	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d", &n);

		all.clear();
		while(n != 0) {
			all.push_back(n % 10);
			n /= 10;
		}
		sort(all.begin(), all.end());

		int res = 0;
		do {
			res += prime[toInt()];
		} while(next_permutation(all.begin(), all.end()));
		printf("%d\n", res);
	}

  return 0;
}
