#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int l, n, a[53], dp[53][53];

int rec(int i, int j) {
	int &ret = dp[i][j];
	if(ret != -1) return ret;
	ret = 1e9;

	for(int k = i + 1; k < j; ++k)
		ret = min(ret, rec(i, k) + rec(k, j) + (a[j] - a[i]));

	if(ret >= 1e9)
		ret = 0;

	return ret;
}

int main() {
	while(scanf("%d", &l) && l != 0) {
		scanf("%d", &n);
		a[0] = 0;
		for(int i = 1; i <= n; ++i)
			scanf("%d", a + i);
		a[n + 1] = l;
		sort(a, a + n + 1);

		memset(dp, -1, sizeof dp);
		printf("The minimum cutting is %d.\n", rec(0, n + 1));
	}
}

