#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
char s[N];
int t, k, len, dp[N][N];

int rec(int i, int j) {
	if(i > j)
		return 0;
	int &ret = dp[i][j];
	if(ret != -1)
		return ret;
	return ret = rec(i + 1, j - 1) + (s[i] != s[j]);
}

int main() {
	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%s %d", s, &k);
		len = strlen(s);

		memset(dp, -1, sizeof dp);
		
		int res = 0;
		for(int i = 0; i < len; ++i)
			for(int j = i; j < len; ++j)
				if(rec(i, j) <= k)
					res = max(res, j - i + 1);

		printf("%d\n", res);
	}

	return 0;
}
