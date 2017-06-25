#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int const N = 2 * 1e5 + 1, MOD = 1e9 + 7;
int dp[N][2];

int main() {
	int n, m, mxh = 0;

	scanf("%d%d", &n, &m);
	if(n < m)
		swap(n, m);

	bool f = false;

	for(int i = 895; i > 0; --i, f = !f)
		for(int j = 0; j <= n; ++j) {
			int rrem = n - j;
			int grem = min(m - (i * (i - 1) / 2) + j, m);

			if(rrem >= i) dp[j][f] = max(dp[j][f], dp[j + i][!f] + 1);
			if(grem >= i) dp[j][f] = max(dp[j][f], dp[j][!f] + 1);
		}
	for(int i = 0; i <= n; ++i)
		mxh = max(mxh, dp[i][!f]);

	memset(dp, 0, sizeof dp);
	for(int i = 0; i <= n; ++i)
		dp[i][!f] = 1;
	for(int i = mxh; i > 0; --i, f = !f)
		for(int j = 0; j <= n; ++j) {
			int r1 = 0, r2 = 0;
			int rrem = n - j;
			int grem = min(m - (i * (i - 1) / 2) + j, m);

			if(rrem >= i) r1 = dp[j + i][!f];
			if(grem >= i) r2 = dp[j][!f];
			dp[j][f] = (r1 + r2) % MOD;
		}

	printf("%d\n", dp[0][!f]);

	return 0;
}

