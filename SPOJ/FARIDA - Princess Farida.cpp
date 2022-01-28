#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 1;
int t, n, coins[N];
long long dp[N];

long long rec(int idx) {
	if(idx >= n) {
		return 0;
	}

	long long &res = dp[idx];
	if(res != -1) {
		return res;
	}

	res = max(rec(idx + 1), rec(idx + 2) + coins[idx]);
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	for(int i = 1; i <= t; ++i) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", coins + i);
		}

		memset(dp, -1, sizeof dp);
		printf("Case %d: %lld\n", i, rec(0));
	}

	return 0;
}

