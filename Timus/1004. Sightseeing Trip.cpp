#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n, m, cost[N], mat[N][N], par[N], l[N];
bool vis[N];
vector<vector<pair<int, int> > > g;
priority_queue<pair<int, int> > q;
vector<int> sol, tmp;

int Dijkstra(int src, bool ok, int val) {
	fill(cost, cost + N, 2e9);
	memset(par, -1, sizeof par);
	memset(vis, false, sizeof vis);
	memset(l, 0, sizeof l);
	while(!q.empty()) q.pop();

	cost[src] = 0;
	par[src] = src;
	l[src] = 0;
	q.push({0, src});

  int best = 2e9;
	while(!q.empty()) {
		int v = q.top().second;
		int c = -q.top().first;
		q.pop();

		if(vis[v])
			continue;
		vis[v] = true;
		
		for(int i = 0, u, nc; i < g[v].size(); ++i) {
			u = g[v][i].first;
			nc = g[v][i].second;

			if(vis[u] && par[v] != u && l[v] + l[u] >= 2) {
				if(ok && cost[v] + cost[u] + nc == val) {
					sol.clear();
					tmp.clear();
					sol.push_back(src);

					while(par[v] != v) {
						if(v == src)
							break;
						tmp.push_back(v);
						v = par[v];
					}

					reverse(tmp.begin(), tmp.end());
					sol.insert(sol.end(), tmp.begin(), tmp.end());

					while(par[u] != u) {
						if(u == src)
							break;
						sol.push_back(u);
						u = par[u];
					}
					
					return 0;
				}

        if(!ok)
				  best = min(best, cost[v] + cost[u] + nc);
			}

			if(c + nc < cost[u]) {
				cost[u] = c + nc;
				par[u] = v;
				l[u] = l[v] + 1;
				q.push({-cost[u], u});
			}
		}
	}

	return best;
}

int main() {
	while(scanf("%d", &n) && n != -1) {
		for(int i = 0; i < N; ++i)
			fill(mat[i], mat[i] + N, 2e9);

		scanf("%d", &m);
		for(int i = 0, a, b, c; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			--a, --b;
			
			mat[a][b] = mat[b][a] = min(mat[a][b], c);
		}

		g.clear();
		g.resize(n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(mat[i][j] != 2e9)
					g[i].push_back({j, mat[i][j]});
		
		int res = 2e9, best = 2e9, idx;
		for(int i = 0; i < n; ++i) {
			res = min(res, Dijkstra(i, false, best));
			if(res < best)
				best = res, idx = i;
		}

		if(res == 2e9)
			puts("No solution.");
		else {
			Dijkstra(idx, true, best);
			for(int i = 0; i < sol.size(); ++i)
				printf("%s%d", i == 0 ? "" : " ", sol[i] + 1);
			puts("");
		}
	}

  return 0;
}
