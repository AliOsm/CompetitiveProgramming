#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
long long n, k, a[N];

int main() {
	scanf("%lld %lld", &n, &k);
	for(int i = 0; i < k; ++i)
		scanf("%lld", a + i);

	if(n == 0) {
		cout << 1 << ' ' << 0 << endl;
		return 0;
	}

	long long mn = 2e18, idx = k - 1;
	for(int i = 0; i < k; ++i) {
		if(a[i] <= n && n % a[i] < mn) {
			mn = n % a[i];
			idx = i;
		}
	}

	cout << idx + 1 << ' ' << n / a[idx] << endl;

	return 0;
}

