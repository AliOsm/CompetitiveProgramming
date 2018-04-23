#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n;
char g[4][N][N], v1[N][N], v2[N][N];

int rec(int idx, int r1, int r2) {
	if(r1 < 0 || r2 < 0)
		return 1e9;

	if(idx == 4)
		return 0;

	int ret1 = 0, ret2 = 0;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			if(g[idx][i][j] != v1[i][j])
				++ret1;
			if(g[idx][i][j] != v2[i][j])
				++ret2;
		}

	return min(rec(idx + 1, r1 - 1, r2) + ret1, rec(idx + 1, r1, r2 - 1) + ret2);
}

int main() {
	scanf("%d", &n);

	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%s", g[i][j]);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			if(i % 2 == 0 && j % 2 == 0)
				v1[i][j] = '0', v2[i][j] = '1';
			else if(i % 2 == 0 && j % 2 == 1)
				v1[i][j] = '1', v2[i][j] = '0';
			else if(i % 2 == 1 && j % 2 == 0)
				v1[i][j] = '1', v2[i][j] = '0';
			else
				v1[i][j] = '0', v2[i][j] = '1';
		}

	cout << rec(0, 2, 2) << endl;

  return 0;
}
