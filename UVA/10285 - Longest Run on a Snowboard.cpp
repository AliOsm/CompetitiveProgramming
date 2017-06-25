#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>

using namespace std;

int n, m, ni, nj, g[101][101], dp[101][101];
int di[] = { 1, 0, -1, 0 };
int dj[] = { 0, -1, 0, 1 };
string s;

int rec(int i, int j) {
	int &ret = dp[i][j];
	if(ret != -1) return ret;
	ret = 0;

	for(int k = 0; k < 4; ++k) {
		ni = i + di[k];
		nj = j + dj[k];

		if(ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] > g[i][j])
			ret = max(ret, rec(ni, nj) + 1);
	}

	return ret;
}

int main() {
	int t;
	scanf("%d", &t);

	int res;
	while(t--) {
		cin >> s;
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);

		memset(dp, -1, sizeof dp);
		res = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				res = max(res, rec(i, j) + 1);

		printf("%s: %d\n", s.c_str(), res);
	}
}

