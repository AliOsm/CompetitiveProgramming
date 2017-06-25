#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

int const N = 101;
int m, n, dp[N][N * 4000];
pair<int, int> a[N];

int rec(int i, int sum) {
	if(sum > m + 200)
		return -1e9;

	if(i == n) {
		if(sum <= m || (sum > 2000 && sum - 200 <= m))
			return 0;

		return -1e9;
	}

	int &ret = dp[i][sum];
	if(ret != -1) return ret;
	ret = 0;

	return ret = max(rec(i + 1, sum),
			  	     rec(i + 1, sum + a[i].first) + a[i].second);;
}

int main() {
	while(scanf("%d%d", &m, &n) == 2) {
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &a[i].first, &a[i].second);

		memset(dp, -1, sizeof dp);
		printf("%d\n", rec(0, 0));
	}

	return 0;
}

