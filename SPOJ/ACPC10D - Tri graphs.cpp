#include <stdio.h>
#include <memory.h>
#include <algorithm>

typedef long long ll;

using namespace std;

int const N = 1e5 + 1;
int n, grid[N][3];
ll dp[N][3];

ll rec(int i, int j) {
	if(i == n - 1) {
		if(j == 0) return grid[n - 1][0] + grid[n - 1][1];
		else if(j == 1) return grid[n - 1][1];
		else if(j == 2) return 1e9;
	}

	ll &ret = dp[i][j];
	if(ret != -1e9) return ret;
	ret = 1e9;

	if(j == 0) {
		ret = min(ret, rec(i + 1, j) + grid[i][j]);
		ret = min(ret, rec(i, j + 1) + grid[i][j]);
		ret = min(ret, rec(i + 1, j + 1) + grid[i][j]);
	} else if(j == 1) {
		ret = min(ret, rec(i + 1, j) + grid[i][j]);
		ret = min(ret, rec(i, j + 1) + grid[i][j]);
		ret = min(ret, rec(i + 1, j + 1) + grid[i][j]);
		ret = min(ret, rec(i + 1, j - 1) + grid[i][j]);
	} else if(j == 2) {
		ret = min(ret, rec(i + 1, j) + grid[i][j]);
		ret = min(ret, rec(i + 1, j - 1) + grid[i][j]);
	}

	return ret;
}

int main() {
	for(int cnt = 1; scanf("%d", &n) && n != 0; ++cnt) {
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j < 3; ++j)
				dp[i][j] = -1e9;

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 3; ++j)
				scanf("%d", &grid[i][j]);

		printf("%d. %lld\n", cnt, rec(0, 1));
	}

	return 0;
}

