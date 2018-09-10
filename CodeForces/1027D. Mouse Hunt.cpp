/*
  Idea:
    - Find cycles and from each cycle take the minimum cost.
    - It is true because the graph constructed in this problem
      forses the Mouse to go to any cycle and stay in it, so
      it is enough to put 1 trap in each cycle.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, c[N], comp[N], id, dfs, idx[N], low[N];
bool in[N], vis[N];
vector<int> st;
vector<vector<int> > g, ng, comps;

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
      comps[id].push_back(node);
      comp[node] = id;
      in[node] = false;
      st.pop_back();
    } while(node != v);
    ++id;
  }
}

int main() {
  scanf("%d", &n);
  g.resize(n);
  comps.resize(n);
  for(int i = 0; i < n; ++i)
    scanf("%d", c + i);
  for(int i = 0, tmp; i < n; ++i) {
    scanf("%d", &tmp), --tmp;
    g[i].push_back(tmp);
  }

  memset(idx, -1, sizeof idx);
  dfs = id = 0;
  for(int i = 0; i < n; ++i)
    if(idx[i] == -1)
      DFS(i);

  ng.resize(n);
  for(int i = 0; i < g.size(); ++i)
    for(int j = 0; j < g[i].size(); ++j)
      if(comp[i] != comp[g[i][j]])
        ng[comp[i]].push_back(comp[g[i][j]]);

  int res = 0;
  for(int i = 0; i < id; ++i)
    if(ng[i].size() == 0) {
      int mn = 1e9;
      for(int j = 0; j < comps[i].size(); ++j)
        mn = min(mn, c[comps[i][j]]);
      res += mn;
    }

  printf("%d\n", res);

  return 0;
}
