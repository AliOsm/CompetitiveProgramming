#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, m, id, dfs, idx[N], low[N], tmp;
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
			st.pop_back();
		} while(node != v);
		++id;
	}
}

int main() {
	scanf("%d", &t);
	tmp = 0;
	while(t-- != 0) {
		if(tmp == -1)
			break;

		scanf("%d %d", &n, &m);
		g.clear();
		g.resize(n);
		for(int i = 0, a, b; i < m; ++i) {
			scanf("%d %d", &a, &b);
			--a, --b;
			g[a].push_back(b);
		}
		scanf("%d", &tmp);

		memset(idx, -1, sizeof idx);
		memset(in, false, sizeof in);
		dfs = id = 0;
		for(int i = 0; i < n; ++i)
			if(idx[i] == -1)
				DFS(i);

		printf("%d\n", id);
	}

  return 0;
}
