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
				++bridges[v], ++bridges[u];
		} else if(u != p)
			low[v] = min(low[v], idx[u]);
	}
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {
	while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
		g.clear();
		g.resize(n);

		int a, b;
		while(scanf("%d %d", &a, &b) && a != -1 && b != -1) {
			g[a].push_back(b);
			swap(a, b);
			g[a].push_back(b);
		}

		memset(idx, -1, sizeof idx);
		dfs = 0;
		DFS(0, -1);

		sol.clear();
		for(int i = 0; i < g.size(); ++i) {
			if(bridges[i] == g[i].size())
				sol.push_back({i, bridges[i]});
			else if(bridges[i] < g[i].size())
				sol.push_back({i, bridges[i] + 1});
		}

		sort(sol.begin(), sol.end(), cmp);

		for(int i = 0; i < m; ++i)
			printf("%d %d\n", sol[i].first, sol[i].second);
		puts("");
	}

  return 0;
}