#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;

int n, dp[1000001][10];

int digitAt(int m, int p) {
	return int(m / pow(10, p)) % 10;
}

int rec(int m, int i) {
	if(m == 0)
		return 0;

	if(m < 0)
		return 1e9;

	if(i > log10(m) + 1)
		return 1e9;

	int &ret = dp[m][i];
	if(ret != -1) return ret;
	ret = 1e9;

	ret = min(ret, rec(m - digitAt(m, i), 0) + 1);
	ret = min(ret, rec(m, i + 1));

	return ret;
}

int main() {
	scanf("%d", &n);

	memset(dp, -1, sizeof dp);
	printf("%d\n", rec(n, 0));
}
