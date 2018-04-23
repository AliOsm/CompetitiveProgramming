#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, m, id, dfs, idx[N], low[N], belongsTo[N], dag[N];
bool in[N];
vector<int> st;
vector<vector<int> > g;

void DFS(int v) {
	idx[v] = low[v] = dfs++;
	in[v] = true;
	st.push_back(v);

	for(int i = 0, u; i < g[v].size(); ++i) {
		u = g[v][i];
		if(idx[u] == -1) {
			DFS(u);
			low[v] = min(low[v], low[u]);
		} else if(in[u])
			low[v] = min(low[v], low[u]);
	}

	if(low[v] == idx[v]) {
		int node;
		do {
			node = st.back();
			in[node] = false;
			belongsTo[node] = id;
			st.pop_back();
		} while(node != v);
		++id;
	}
}

int main() {
	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d %d", &n, &m);
		g.clear();
		g.resize(n);
		for(int i = 0, a, b; i < m; ++i) {
			scanf("%d %d", &a, &b);
			--a, --b;
			g[a].push_back(b);
		}

		memset(idx, -1, sizeof idx);
		memset(in, false, sizeof in);
		memset(belongsTo, -1, sizeof belongsTo);
		dfs = id = 0;
		for(int i = 0; i < n; ++i)
			if(idx[i] == -1)
				DFS(i);

		memset(dag, 0, sizeof dag);
		for(int i = 0; i < g.size(); ++i)
			for(int j = 0; j < g[i].size(); ++j)
				if(belongsTo[i] != belongsTo[g[i][j]])
					++dag[belongsTo[g[i][j]]];

		int res = 0;
		for(int i = 0; i < id; ++i)
			if(dag[i] == 0)
				++res;

		printf("%d\n", res);
	}

  return 0;
}
