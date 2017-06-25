#include <stdio.h>
#include <memory.h>

using namespace std;

int const N = 1000001;
long long cm[1000001];
bool prime[N];

void sieve() {
	memset(prime, true, sizeof prime);
	prime[0] = prime[1] = false;

	for(int i = 2; i * i < N; ++i)
		if(prime[i])
			for(int j = i * i; j < N; j += i)
				prime[j] = false;
}

int main() {
	sieve();

	cm[0] = 0;
	for(int i = 1; i < N; ++i)
		cm[i] = cm[i - 1] + (prime[i] ? i : 0);

	int t, n;
	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d", &n);
		printf("%lld\n", cm[n]);
	}

    return 0;
}

