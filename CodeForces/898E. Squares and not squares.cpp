#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

long long const N = 3e5 + 1;
long long n, a[N], mn[N], sqrs[32001], cnt = 0;
bool vis[N];

int main() {
	for(int i = 0; i < 32001; ++i)
		sqrs[i] = i * i;

	scanf("%lld", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
		if(binary_search(sqrs, sqrs + 32001, a[i])) {
			vis[i] = true;
			++cnt;
		}
	}

	if(cnt == n / 2) {
		puts("0");
		return 0;
	}

	for(int i = 0, idx; i < n; ++i) {
		idx = lower_bound(sqrs, sqrs + 32001, a[i]) - sqrs;
		if(idx < 32001 && sqrs[idx] == a[i])
			mn[i] = 0;
		else {
			long long after = 2e16, before = 2e16;
			if(idx < 32001)
				after = abs(sqrs[idx] - a[i]);

			if(idx - 1 >= 0)
				before = abs(a[i] - sqrs[idx - 1]);

			mn[i] = min(after, before);
		}
	}

	long long sol = 0;

	if(cnt > n / 2) {
		cnt -= (n / 2);
		for(int i = 0; cnt > 0 && i < n; ++i) {
			if(vis[i] && a[i] != 0) {
				++sol;
				--cnt;
			}
		}

		for(int i = 0; cnt > 0 && i < n; ++i) {
			if(vis[i] && a[i] == 0) {
				sol += 2;
				--cnt;
			}
		}

		printf("%lld\n", sol);
		return 0;
	}

	sort(mn, mn + n);

	for(int i = 0; i < n / 2; ++i)
		sol += mn[i];

	printf("%lld\n", sol);

	return 0;
}

