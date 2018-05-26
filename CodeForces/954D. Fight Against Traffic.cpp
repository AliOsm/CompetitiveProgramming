/*
	Idea:
		- Brute force.
		- Calculate the distance between `s` and all other nodes.
		- Calculate the distance between `t` and all other nodes.
		- Try all pair of nodes u and v, then if:
			d(s, u) + 1 + d(v, t) is less than d(s, t)
			and
			d(s, v) + 1 + d(u, t) is less than d(s, t)
			then add 1 to the result.
		- d(u, v) is the shortest distance between nodes u and v.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
int n, m, s, t, d, cost[N][2], res;
bool vis[N], edges[N][N];
vector<vector<int> > g;
queue<int> q;

void bfs(int src, int idx) {
	while(!q.empty()) q.pop();
	memset(vis, 0, sizeof vis);
	q.push(src);
	vis[src] = true;
	cost[src][idx] = 0;
	while(!q.empty()) {
		int fr = q.front();
		q.pop();

		for(int i = 0; i < g[fr].size(); ++i)
			if(!vis[g[fr][i]]) {
				q.push(g[fr][i]);
				vis[g[fr][i]] = true;
				cost[g[fr][i]][idx] = cost[fr][idx] + 1;
			}
	}
}

int main() {
  scanf("%d %d %d %d", &n, &m, &s, &t);
  --s, --t;
  g.resize(n);
  for(int i = 0, a, b; i < m; ++i) {
  	scanf("%d %d", &a, &b);
  	--a, --b;
  	edges[a][b] = edges[b][a] = true;
  	g[a].push_back(b);
  	swap(a, b);
  	g[a].push_back(b);
  }

  bfs(s, 0);
  d = cost[t][0];
  bfs(t, 1);

  for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j) {
			if(edges[i][j])
				continue;
			if(cost[i][0] + 1 + cost[j][1] >= d && cost[i][1] + 1 + cost[j][0] >= d)
				++res;
		}

  printf("%d\n", res);

  return 0;
}

