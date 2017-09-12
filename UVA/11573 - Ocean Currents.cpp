#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1, oo = 1e9 + 1;
int n, m, q, x, y, xx, yy, cost[N][N];
int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
char g[N][N];
bool vis[N][N];
deque<pair<int, int> > dq;

int bfs(int x, int y, int xx, int yy) {
	for(int i = 0; i < n; ++i)
		fill(cost[i], cost[i] + N, oo);
	memset(vis, false, sizeof vis);
	while(!dq.empty()) dq.pop_back();

	cost[x][y] = 0;
	dq.push_front(make_pair(x, y));

	while(!dq.empty()) {
		int i = dq.front().first, j = dq.front().second;
		dq.pop_front();

		if(i == xx && j == yy)
			return cost[xx][yy];

		if(vis[i][j])
			continue;
		vis[i][j] = true;

		for(int k = 0, ni, nj, c; k < 8; ++k) {
			ni = i + di[k];
			nj = j + dj[k];

			if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
				bool ok = (k != (g[i][j] - '0'));
				c = cost[i][j] + ok;

				if(c < cost[ni][nj]) {
					cost[ni][nj] = c;
					if(ok)
						dq.push_back(make_pair(ni, nj));
					else
						dq.push_front(make_pair(ni, nj));
				}
			}
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%s", g[i]);

	scanf("%d", &q);
	while(q-- != 0) {
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		--x, --y, --xx, --yy;
		printf("%d\n", bfs(x, y, xx, yy));
	}

	return 0;
}

