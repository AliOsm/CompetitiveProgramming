#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int n, m, a[51];
long long dp[251][51];

long long rec(int rem, int index) {
	if(index >= m)
		return 0;

	if(rem < 0)
		return 0;

	if(rem == 0)
		return 1;

	long long &ret = dp[rem][index];
	if(ret != -1) return ret;
	ret = 0;

	ret += rec(rem - a[index], index);
	ret += rec(rem, index + 1);

	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i)
		scanf("%d", a + i);

	memset(dp, -1, sizeof dp);
	printf("%lld\n", rec(n, 0));

	return 0;
}

