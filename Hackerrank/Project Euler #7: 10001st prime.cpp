#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

bool prime[1000001];
vector<int> primes;

void sieve() {
	memset(prime, true, sizeof prime);
	prime[0] = prime[1] = false;

	for(int i = 2; i * i < 1000001; ++i)
		if(prime[i])
			for(int j = i * i; j < 1000001; j += i)
				prime[j] = false;

	for(int i = 0; i < 1000001; ++i)
		if(prime[i])
			primes.push_back(i);
}

int main() {
    sieve();

    int t, n;
    scanf("%d", &t);
    while(t-- != 0) {
    	scanf("%d", &n);
    	printf("%d\n", primes[n - 1]);
    }

    return 0;
}

