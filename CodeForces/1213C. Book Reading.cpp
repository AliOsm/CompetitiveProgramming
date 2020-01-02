#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int q;
long long n, m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &q);
	while(q-- != 0) {
		scanf("%lld %lld", &n, &m);

		if(m > n) {
			puts("0");
			continue;
		}

		vector<int> all;
		for(long long i = m; i <= n; i += m) {
			if(i != m && all[0] == i % 10)
				break;
			all.push_back(i % 10);
		}

		long long res = 0;
		for(int i = 0; i < all.size(); ++i)
			res += all[i];

		long long mm = m * all.size();
		res = n / mm * res;
		long long rem = n % mm;
		for(int i = 0; i < all.size(); ++i) {
			if(rem - m < 0)
				break;
			res += all[i];
			rem -= m;
		}
		printf("%lld\n", res);
	}

	return 0;
}