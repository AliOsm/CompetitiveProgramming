#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n, mx, a[N];
long long tot;

vector<long long> divisors(long long m) {
	vector<long long> ret;

	long long sqrtm = sqrt(m) + 1;
	for(long long i = 1; i < sqrtm; ++i) {
		if(m % i == 0) {
			ret.push_back(i);
			ret.push_back(m / i);
		}
	}

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		mx = max(mx, a[i]);
	}

	for(int i = 0; i < n; ++i)
		tot += (mx - a[i]);

	vector<long long> d = divisors(tot);
	sort(d.begin(), d.end());

	for(int i = 0, j = d.size() - 1; i < d.size(); ++i, --j) {
		bool ok = true;
		for(int k = 0; k < n; ++k)
			if((mx - a[k]) % d[j] != 0) {
				ok = false;
				break;
			}
		if(ok) {
			printf("%lld %lld\n", d[i], d[j]);
			return 0;
		}
	}

	return 0;
}