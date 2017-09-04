#include <bits/stdc++.h>

using namespace std;

int const N = 201;
int n, m, x, y;
int di[] = { 1, -1, 2, -2, 1, -1, 2, -2 };
int dj[] = { 2, -2, 1, -1, -2, 2, -1, 1 };
bool vis[N][N];

int DFS(int i, int j) {
	if(i <= 0 || i > n || j <= 0 || j > m || vis[i][j])
		return -1;

	vis[i][j] = true;

	int res = 0;
	for(int k = 0, ni, nj; k < 8; ++k) {
		ni = i + di[k];
		nj = j + dj[k];
		res += DFS(ni, nj) + 1;
	}

	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d %d %d %d", &n, &m, &x, &y);

		memset(vis, false, sizeof vis);
		printf("%d\n", DFS(x, y) + 1);
	}

    return 0;
}

