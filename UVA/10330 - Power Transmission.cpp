/*
	Idea:
		- Change each node to two nodes with edge between them with value
			same as the value of the original node, then do max flow algorithm.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 210;
int n, m, b, d, s, t, a[N], bb[N], dd[N], g[N][N], p[N];
bool vis[N];

int DFS(int u, int mn) {
	if(u == t)
		return mn;

	vis[u] = true;

	int ret = 0;
	for(int i = 0; i < n; ++i) {
		if(!vis[i] && g[u][i] > 0) {
			p[i] = u;
			if(mn == -1)
				ret = max(ret, DFS(i, g[u][i]));
			else
				ret = max(ret, DFS(i, min(mn, g[u][i])));
			vis[i] = true;
			if(ret != 0)
				break;
		}
	}

	return ret;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		memset(g, 0, sizeof g);
		for(int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			g[i][i + n] = a[i];
		}

		scanf("%d", &m);
		for(int i = 0, a, b, c; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			--a, --b;
			g[a + n][b] += c;
		}

		n *= 2;

		scanf("%d %d", &b, &d);

		for(int i = 0; i < b; ++i) {
			scanf("%d", bb + i);
			--bb[i];
			g[n][bb[i]] = 1e9;
		}
		s = n, a[n] = 1e9, ++n;

		for(int i = 0; i < d; ++i) {
			scanf("%d", dd + i);
			--dd[i];
			g[dd[i] + (n / 2)][n] = 1e9;
		}
		t = n, a[n] = 1e9, ++n;

		p[s] = -1;
		int maxFlow = 0;
		while(true) {
			memset(vis, false, sizeof vis);
			int res = DFS(s, -1);

			if(res == 0)
				break;

			int cur = t;
			while(p[cur] != -1) {
				g[p[cur]][cur] -= res;
				g[cur][p[cur]] += res;
				cur = p[cur];
			}

			maxFlow += res;
		}

		printf("%d\n", maxFlow);
	}

	return 0;
}
