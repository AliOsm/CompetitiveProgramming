#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 1;
int n, m, idx[N], low[N], dfs, bridges[N];
vector<vector<int> > g;
vector<pair<int, int> > sol;

void DFS(int v, int p) {
	low[v] = idx[v] = dfs++;

	for(int i = 0, u; i < g[v].size(); ++i) {
		u = g[v][i];
		if(idx[u] == -1) {
			DFS(u, v);
			low[v] = min(low[v], low[u]);

			if(low[u] > idx[v])
				sol.push_back({min(v, u), max(u, v)});
		} else if(u != p)
			low[v] = min(low[v], idx[u]);
	}
}

int main() {
	while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
		g.clear();
		g.resize(n);

		int a, b;
		for(int i = 0; i < m; ++i) {
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			swap(a, b);
			g[a].push_back(b);
		}

		memset(idx, -1, sizeof idx);
		dfs = 0;
		sol.clear();
		DFS(0, -1);
		sort(sol.begin(), sol.end());

		printf("%d", int(sol.size()));
		for(int i = 0; i < sol.size(); ++i)
			printf(" %d %d", sol[i].first, sol[i].second);
		puts("");
	}

  return 0;
}