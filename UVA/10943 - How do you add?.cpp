#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int const MOD = 1000000;
int dp[101][101];

int rec(int n, int k) {
	if(n < 0 || k < 0)
		return 0;

	if(n == 0 && k == 0)
		return 1;

	int &ret = dp[n][k];
	if(ret != -1)
		return ret;
	ret = 0;

	for(int i = 0; i <= n; ++i)
		ret += rec(n - i, k - 1) % MOD;

	return ret %= MOD;
}

int main() {
	int n, k;
	while(scanf("%d %d", &n, &k) && n != 0 && k != 0) {
		memset(dp, -1, sizeof dp);
		printf("%d\n", rec(n, k));
	}

	return 0;
}

