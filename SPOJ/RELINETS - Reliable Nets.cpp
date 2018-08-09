/*
  idea:
    - Brute force.
    - Using bitmask we can try every subset of edges and check if it is the minimum one.
    - To check the subset if it is right or not, we can do DFS using the full subset and check if
      the graph connected, then using the subset except each edge at a time and check if the
      graph connected or not.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 20;
struct edge {
  int u, v, c;
  edge() {}
  edge(int u, int v, int c) : u(u), v(v), c(c) {}
} edges[N], taken[N];

bool vis[N];
int n, m, s1, s2;
vector<vector<pair<int, int> > > g;

void DFS(int u) {
  vis[u] = true;

  for(int i = 0; i < g[u].size(); ++i) {
    if(vis[g[u][i].first] ||
      (min(u, g[u][i].first) == min(s1, s2) && max(u, g[u][i].first) == max(s1, s2)))
      continue;
    DFS(g[u][i].first);
  }
}

bool is_connected() {
  memset(vis, false, sizeof vis);

  bool comp = false;
  for(int i = 0; i < n; ++i)
    if(!vis[i]) {
      if(comp)
        return false;
      DFS(i);
      comp = true;
    }

  return true;
}

int main() {
  int kase = 1;
  while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
    for(int i = 0; i < m; ++i) {
      scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].c);
      --edges[i].u, --edges[i].v;
    }

    long long best = 2e18, cur;
    for(int i = 0, e; i < (1 << m); ++i) {
      e = __builtin_popcount(i);
      if(e < n)
        continue;

      cur = 0;
      g.clear();
      g.resize(n);
      for(int j = 0, cnt = 0; j < m; ++j)
        if((i >> j) & 1) {
          g[edges[j].u].push_back(make_pair(edges[j].v, edges[j].c));
          g[edges[j].v].push_back(make_pair(edges[j].u, edges[j].c));
          cur += edges[j].c;
          taken[cnt++] = edges[j];
        }

      s1 = s2 = -1;
      if(!is_connected())
        continue;

      bool ok = true;
      for(int j = 0; j < e; ++j) {
        s1 = taken[j].u, s2 = taken[j].v;
        if(!is_connected()) {
          ok = false;
          break;
        }
      }

      if(ok)
        best = min(best, cur);
    }

    if(best != 2e18)
      printf("The minimal cost for test case %d is %lld.\n", kase++, best);
    else
      printf("There is no reliable net possible for test case %d.\n", kase++);
  }

  return 0;
}
