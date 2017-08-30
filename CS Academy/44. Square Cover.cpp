#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int const N = 301;
int n, m, grid[N][N], x, y, c;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool vis[100001];

void DFS(int i, int j) {
	++c;
	x = max(x, i);
	y = max(y, j);

	int tmp = grid[i][j];
	grid[i][j] = -1;
	for(int k = 0, ni, nj; k < 4; ++k) {
		ni = i + dx[k];
		nj = j + dy[k];

		if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == tmp)
			DFS(ni, nj);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &grid[i][j]);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			if(grid[i][j] != -1) {
				if(!vis[grid[i][j]]) {
					x = i;
					y = j;
					c = 0;
					vis[grid[i][j]] = true;
					DFS(i, j);
				} else {
					puts("0");
					return 0;
				}

				if(x != y || (sqrt(c) * sqrt(c)) != c) {
					puts("0");
					return 0;
				}
			}
		}

	puts("1");

    return 0;
}

