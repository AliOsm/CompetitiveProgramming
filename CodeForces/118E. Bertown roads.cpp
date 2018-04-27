#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m, idx[N], low[N], dfs, bridges;
bool vis[N];
set<pair<int, int> > st;
vector<vector<int> > g;

void DFS(int v, int p) {
	idx[v] = low[v] = dfs++;

	for(int i = 0, u; i < g[v].size(); ++i) {
		u = g[v][i];
		if(idx[u] == -1) {
			DFS(u, v);
			low[v] = min(low[v], low[u]);

			if(low[u] > idx[v])
				++bridges;
		} else if(u != p)
			low[v] = min(low[v], idx[u]);
	}
}

void print(int v, int p) {
	vis[v] = true;

	for(int i = 0, u; i < g[v].size(); ++i) {
		u = g[v][i];

		if(!vis[u]) {
			printf("%d %d\n", v + 1, u + 1);
			st.insert({v, u});
			st.insert({u, v});
			print(u, v);
		} else if(u != p && st.count({v, u}) == 0) {
			st.insert({v, u});
			st.insert({u, v});
			printf("%d %d\n", v + 1, u + 1);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	g.resize(n);
	for(int i = 0, a, b; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		swap(a, b);
		g[a].push_back(b);
	}

	memset(idx, -1, sizeof idx);
	DFS(0, -1);

	if(bridges > 0) {
		puts("0");
		return 0;
	}

	print(0, -1);

  return 0;
}
