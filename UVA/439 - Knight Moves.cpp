#include <iostream>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;

const int N = 8;

queue<pair<int, int> > q;
bool vis[N][N];
int dx[] = { -1, -1, -2, -2, 2, 2, 1, 1 };
int dy[] = { -2, 2, -1, 1, -1, 1, -2, 2 };

string src, des;

int BFS(int sx, int sy, int ex, int ey) {
	int cost = 0, size;

	while (!q.empty()) q.pop();
	memset(vis, false, sizeof vis);
	
	q.push(make_pair(sx, sy));
	vis[sx][sy] = true;

	while (!q.empty() && (++cost) && (size = q.size()))
		while (size--) {
			pair<int, int> fr = q.front();
			q.pop();

			for (int i = 0; i < N; i++) {
				int nx = fr.first + dx[i];
				int ny = fr.second + dy[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N && !vis[nx][ny]) {
					if (ex == nx && ey == ny) return cost;

					vis[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
}

int main() {
	// freopen("input.txt", "r", stdin);
	
	while (cin >> src >> des) {
		if (src == des) {
			cout << "To get from " << src << " to " << des << " takes 0 knight moves." << endl;
			continue;
		}

		int sx = src[0] - 'a';
		int sy = src[1] - '0' - 1;
		int ex = des[0] - 'a';
		int ey = des[1] - '0' - 1;

		cout << "To get from " << src << " to " << des << " takes " << BFS(sx, sy, ex, ey) << " knight moves." << endl;
	}

	return 0;
}
