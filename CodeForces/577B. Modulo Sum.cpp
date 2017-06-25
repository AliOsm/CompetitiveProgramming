#include <stdio.h>
#include <memory.h>

using namespace std;

int const N = 1e6 + 1;
int n, m, a[N], dp[1001][1001][2];

bool rec(int i, int sum, bool take) {
	if(sum == 0 && take)
		return true;

	if(i == n)
		return false;

	int &ret = dp[i][sum][take];
	if(ret != -1) return ret;
	ret = false;

	return ret = (rec(i + 1, (sum + a[i]) % m, true) || rec(i + 1, sum % m, take));
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	if(n > m) {
		puts("YES");
		return 0;
	}

	memset(dp, -1, sizeof dp);
	if(rec(0, 0, 0))
		puts("YES");
	else
		puts("NO");

    return 0;
}

