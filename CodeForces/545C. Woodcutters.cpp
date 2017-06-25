#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;

int n, dp[100001][3];
pair<int, int> a[100001];

int rec(int i, int t) {
	if(i == n)
		return 0;

	if(i == n - 1)
		return 1;

	int &ret = dp[i][t];
	if(ret != -1) return ret;
	ret = 0;

	if(t == 0 || t == 1) {
		ret = max(ret, rec(i + 1, 0));

		if(a[i].first - a[i].second > a[i - 1].first)
			ret = max(ret, rec(i + 1, 1) + 1);

		if(a[i].first + a[i].second < a[i + 1].first)
			ret = max(ret, rec(i + 1, 2) + 1);
	} else {
		ret = max(ret, rec(i + 1, 0));

		if(a[i].first - a[i].second > (a[i - 1].first + a[i - 1].second))
			ret = max(ret, rec(i + 1, 1) + 1);

		if(a[i].first + a[i].second < a[i + 1].first)
			ret = max(ret, rec(i + 1, 2) + 1);
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &a[i].first, &a[i].second);

	memset(dp, -1, sizeof dp);
	printf("%d\n", rec(1, 1) + 1);
}
