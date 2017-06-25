#include <stdio.h>
#include <memory.h>

using namespace std;

int coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
long long dp[30001][11];

long long rec(int rem, int i) {
	if(rem < 0 || i == 11)
		return 0;

	if(rem == 0)
		return 1;

	long long &ret = dp[rem][i];
	if(ret != -1) return ret;

	return ret = rec(rem, i + 1) + rec(rem - coins[i], i);
}

int main() {
	int n, m;
	while(scanf("%d.%d", &n, &m) != EOF && (n != 0 || m != 0)) {
		n *= 100;
		n += m;

		memset(dp, -1, sizeof dp);
		printf("%3d.%02d%17lld\n", (n - m) / 100, m, rec(n, 0));
	}

	return 0;
}

