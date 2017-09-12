#include <bits/stdc++.h>

using namespace std;

int const N = 301;
int n, m, dp[N][N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &dp[i][j]);

	scanf("%d", &m);
	for(int i = 0, a, b, c; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		--a, --b;

		for(int j = 0; j < n; ++j)
			for(int k = 0; k < n; ++k)
				dp[j][k] = min(dp[j][k], min(dp[j][a] + c + dp[b][k], dp[j][b] + c + dp[a][k]));

		long long res = 0;
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < n; ++k)
				res += dp[j][k];

		printf("%lld ", res / 2);
	}

	return 0;
}

