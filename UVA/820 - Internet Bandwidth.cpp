/*
	Idea:
		- Apply direct MaxFlow algorithm
*/

#include <bits/stdc++.h>

using namespace std;

int n, s, t, c, g[101][101], p[101];
bool vis[101];

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
	int kase = 1;
	while(scanf("%d", &n) && n != 0) {
		printf("Network %d\n", kase++);

		memset(g, 0, sizeof g);
		scanf("%d %d %d", &s, &t, &c);
		--s, --t;
		p[s] = -1;
		for(int i = 0, a, b, cc; i < c; ++i) {
			scanf("%d %d %d", &a, &b, &cc);
			--a, --b;
			g[a][b] += cc;
			g[b][a] += cc;
		}

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

		printf("The bandwidth is %d.\n", maxFlow);
		puts("");
	}

	return 0;
}
