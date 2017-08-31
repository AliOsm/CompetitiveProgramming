#include <stdio.h>

using namespace std;

int const N = 1e6 + 1;
int a, b, k, cs[N];
bool prime[N];

void sieve() {
	memset(prime, true, sizeof prime);
	prime[0] = prime[1] = false;

	for(int i = 2; i * i < N; ++i)
		if(prime[i])
			for(int j = i * i; j < N; j += i)
				prime[j] = false;

	cs[0] = 0;
	for(int i = 1; i <= N; ++i)
		cs[i] = cs[i - 1] + prime[i - 1];
}

bool can(int mid) {
	for(int i = a; i <= b - mid + 1; ++i)
		if(cs[i + mid] - cs[i] < k)
			return false;
	return true;
}

int main() {
	sieve();

	scanf("%d %d %d", &a, &b, &k);

	int l = 1, r = b - a + 1, mid, res = -1;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(can(mid)) {
			r = mid - 1;
			res = mid;
		} else
			l = mid + 1;
	}

	printf("%d\n", res);

    return 0;
}
