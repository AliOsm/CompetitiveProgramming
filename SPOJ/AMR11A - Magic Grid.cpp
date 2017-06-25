#include <stdio.h>
#include <algorithm>

using namespace std;

int const N = 501;
int n, m, g[N][N], dp[N][N];

bool can(int mid) {
	g[0][0] = dp[0][0] = mid;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(i == 0 && j == 0)
				continue;
			else if(i == 0) {
				if(dp[i][j - 1] <= 0)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i][j - 1] + g[i][j];
			} else if(j == 0) {
				if(dp[i - 1][j] <= 0)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i - 1][j] + g[i][j];
			} else {
				if(max(dp[i - 1][j], dp[i][j - 1]) <= 0)
					dp[i][j] = 0;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
			}

	return dp[n - 1][m - 1] > 0;
}

int main() {
	int t, l, r, mid, res;
	scanf("%d", &t);

	while(t-- != 0) {
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);

		l = 1, r = 1e9 + 1, res = 1;
		while(l <= r) {
			mid = (l + r) / 2;

			if(can(mid)) {
				r = mid - 1;
				res = mid;
			} else
				l = mid + 1;
		}

		printf("%d\n", res);
	}
}

