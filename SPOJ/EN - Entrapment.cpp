#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, m, idx[N], low[N], dfs, cost[2][N];
bool vis[N];
vector<vector<int> > g;
vector<pair<int, int> > edges;
set<int> ap;
queue<int> q;

void DFS(int v, int par) {
	idx[v] = low[v] = dfs++;

	int ch = 0;
	for(int i = 0, u; i < g[v].size(); ++i) {
		u = g[v][i];
		if(idx[u] == -1) {
			++ch;

			DFS(u, v);
			low[v] = min(low[v], low[u]);

			if(par == -1 && ch > 1)
				ap.insert(v);
			else if(par != -1 && low[u] >= idx[v])
				ap.insert(v);
		} else if(par != u)
			low[v] = min(low[v], idx[u]);
	}
}

int BFS(int src, int idx) {
	memset(cost[idx], 0, sizeof cost[idx]);
	memset(vis, false, sizeof vis);
	while(!q.empty()) q.pop();

	q.push(src);

	while(!q.empty()) {
		int fr = q.front();
		q.pop();

		if(vis[fr])
			continue;
		vis[fr] = true;

		for(int i = 0; i < g[fr].size(); ++i) {
			cost[idx][g[fr][i]] = cost[idx][fr] + 1;
			q.push(g[fr][i]);
		}
	}

	return 0;
}

int main() {
	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d %d", &n, &m);

		g.clear();
		g.resize(n);
		edges.clear();
		edges.resize(m);
		for(int i = 0, a, b; i < m; ++i) {
			scanf("%d %d", &a, &b);
			--a, --b;
			g[a].push_back(b);
			g[b].push_back(a);
			edges[i] = {a, b};
		}

		memset(idx, -1, sizeof idx);
		ap.clear();
		dfs = 0;
		DFS(0, -1);

		if(ap.empty()) {
			printf("%d\n", n);
		} else {
			BFS(0, 0);
			BFS(n - 1, 1);
			
			int v1 = 1e9, v2 = -1e9, i, v;
			for(set<int>::iterator it = ap.begin(); it != ap.end(); ++it) {
				v = *it;

				if(cost[0][v] < v1 && cost[1][v] > v2) {
					i = v;
					v1 = cost[0][v];
					v2 = cost[1][v];
				}
			}
			printf("%d\n", i + 1);
		}
	}

  return 0;
}
