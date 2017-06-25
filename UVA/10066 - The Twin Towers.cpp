#include <stdio.h>
#include <memory.h>

int const N = 101;
int a[N], b[N], dp[N][N], n1, n2;

inline int max(int a, int b) {
	return a > b ? a : b;
}

int rec(int i = 0, int j = 0) {
	if(i == n1 || j == n2) return 0;

	int &ret = dp[i][j];
	if(ret != -1) return ret;
	ret = 0;

	if(a[i] == b[j])
		return ret = rec(i + 1, j + 1) + 1;

	return ret = max(rec(i + 1, j), rec(i, j + 1));
}

int main() {
	for(int cnt = 1; scanf("%d%d", &n1, &n2) && n1 != 0 && n2 != 0; ++cnt) {
		for(int i = 0; i < n1; ++i)
			scanf("%d", a + i);
		for(int i = 0; i < n2; ++i)
			scanf("%d", b + i);

		memset(dp, -1, sizeof dp);
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", cnt, rec());
	}

	return 0;
}

