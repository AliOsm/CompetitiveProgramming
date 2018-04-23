#include <bits/stdc++.h>

using namespace std;

int n, s, cnt;
long long dp[66][66][3];

long long rec(int idx, int sum, int prv) {
	if(idx == n)
		return sum == s ? 1 : 0;

	long long &ret = dp[idx][sum][prv];
	if(ret != -1)
		return ret;
	ret = 0;

	if(prv > 0)
		ret += rec(idx + 1, sum + 1, 1) + rec(idx + 1, sum, 0);
	else
		ret += rec(idx + 1, sum, 1) + rec(idx + 1, sum, 0);

	return ret;
}

int main() {
	for(cnt = 0; scanf("%d %d", &n, &s) && n >= 1 && s >= 0; ++cnt) {
		if(s > n) {
			puts("0");
			continue;
		} else if(s == n) {
			puts("1");
			continue;
		}

		memset(dp, -1, sizeof dp);
		printf("%lld\n", rec(0, 0, 2));
	}

  return 0;
}
