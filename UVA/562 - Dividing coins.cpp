#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

int const N = 101, M = 50001;
int coins[N], dp[N][M], n, total;

int rec(int i = 0, int sum = 0) {
	if(i == n)
		return abs(sum - (total - sum));

	int &ret = dp[i][sum];
	if(ret != -1) return ret;
	ret = 1e9;

	ret = min(ret, rec(i + 1, sum + coins[i]));
	ret = min(ret, rec(i + 1, sum));

	return ret;
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		total = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", coins + i);
			total += coins[i];
		}

		memset(dp, -1, sizeof dp);
		printf("%d\n", rec());
	}

	return 0;
}

