/*
  Idea:
    - Try to find the minimum spanning tree using `m` edges, `m - 1` edges,
      `m - 2` edges... and so on, and minimize the result.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
struct edge {
  int u, v, c;
  edge() {}
  edge(int u, int v, int c) : u(u), v(v), c(c) {}
  bool operator<(const edge &e) const { return c < e.c; }
} edges[N * N];

bool vis[N];
int n, m, ds[N];
vector<vector<int> > g;

void DFS(int u) {
  vis[u] = true;

  for(int i = 0, v; i < g[u].size(); ++i) {
    v = g[u][i];
    if(!vis[v])
      DFS(v);
  }
}

int find(int x) {
  return x == ds[x] ? x : ds[x] = find(ds[x]);
}

int main() {
  while(scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
    g.clear();
    g.resize(n);
    for(int i = 0, a, b, c; i < m; ++i) {
      scanf("%d %d %d", &a, &b, &c);
      --a, --b;
      edges[i] = edge(a, b, c);
      g[a].push_back(b);
      swap(a, b);
      g[a].push_back(b);
    }

    if(m < n - 1) {
      puts("-1");
      continue;
    }

    memset(vis, false, sizeof vis);
    bool comp = false;
    for(int i = 0; i < n; ++i) {
      if(!vis[i]) {
        if(comp) {
          puts("-1");
          comp = false;
          break;
        }

        comp = true;
        DFS(i);
      }
    }

    if(!comp)
      continue;

    sort(edges, edges + m);

    int res = 1e9, taken, mn, mx;

    for(int st = 0; st < m; ++st) {
      for(int i = 0; i < n; ++i)
        ds[i] = i;

      mn = -1, taken = 0;
      for(int i = st; taken < n - 1 && i < m; ++i) {
        edge e = edges[i];

        if(find(e.u) != find(e.v)) {
          if(mn == -1)
            mn = e.c;
          mx = e.c;
          ++taken;
          ds[find(e.u)] = find(e.v);
        }
      }

      if(taken == n - 1)
        res = min(res, mx - mn);
    }

    printf("%d\n", res);
  }
  
  return 0;
}
