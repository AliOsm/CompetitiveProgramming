#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int const N = 1001;
int n, m, sx, sy;
char board[N][N];
bool vis[N][N][3][4];

void DFS(int x, int y, int turns, int direction) {
	if(turns > 2)
		return;

	if(board[x][y] == 'T') {
		puts("YES");
		exit(0);
	}

	int nx, ny;
	for(int i = 0; i < 4; i++) {
		nx = dx[i] + x;
		ny = dy[i] + y;

		if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != '*' && !vis[nx][ny][turns][i]) {
			vis[nx][ny][turns][i] = true;
			DFS(nx, ny, turns + (i != direction), i);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);

			if(board[i][j] == 'S')
				sx = i, sy = j;
		}

	for(int i = 0; i < 4; i++) {
		memset(vis, false, sizeof vis);
		DFS(sx, sy, 0, i);
	}

	puts("NO");

  return 0;
}

