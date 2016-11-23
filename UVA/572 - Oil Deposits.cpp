#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<string> g;
int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, -1, 1 };

void DFS(int x, int y) {
	g[x][y] = '*';
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == '@') {
			g[nx][ny] == '*';
			DFS(nx, ny);
		}
	}
}

int main() {
	cin >> n >> m;

	while (n) {
		g.clear();
		g.resize(n);

		for (int i = 0; i < n; i++) cin >> g[i];

		int c = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (g[i][j] == '@') {
					c++;
					DFS(i, j);
				}

		cout << c << endl;
		cin >> n >> m;
	}

	return 0;
}
