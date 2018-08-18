/*
  Idea:
    - Count the number of nodes in each node subtree such that there is a
      lucky edge in the path between them.
    - Count the number of nodes for each node outside the subtree of it
      such that there is a lucky edge in the path between them.
    - Use the information from the previous steps to calculate the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
bool vis[N];
int n, f[N], ff[N], siz[N];
vector<vector<pair<int, int> > > g;

bool is_lucky(int x) {
  while(x != 0) {
    if(x % 10 != 4 && x % 10 != 7)
      return false;
    x /= 10;
  }
  return true;
}

void DFS1(int u) {
  vis[u] = true;
  ++siz[u];

  for(int i = 0, v; i < g[u].size(); ++i) {
    v = g[u][i].first;
    if(!vis[v]) {
      DFS1(v);
      siz[u] += siz[v];

      if(is_lucky(g[u][i].second))
        f[u] += siz[v];
      else
        f[u] += f[v];
    }
  }
}

void DFS2(int u) {
  vis[u] = true;

  for(int i = 0, v; i < g[u].size(); ++i) {
    v = g[u][i].first;
    if(!vis[v]) {
      if(is_lucky(g[u][i].second))
        ff[v] = n - siz[v];
      else
        ff[v] = ff[u] + f[u] - f[v];

      DFS2(v);
    }
  }
}

int main() {
  scanf("%d", &n);
  g.resize(n);
  for(int i = 0, a, b, c; i < n - 1; ++i) {
    scanf("%d %d %d", &a, &b, &c);
    --a, --b;
    g[a].push_back({b, c});
    swap(a, b);
    g[a].push_back({b, c});
  }

  DFS1(0);
  memset(vis, false, sizeof vis);
  DFS2(0);

  long long res = 0;
  for(int i = 0; i < n; ++i)
    res += 1ll * f[i] * (f[i] - 1) + 1ll * ff[i] * (ff[i] - 1) + 2ll * f[i] * ff[i];

  printf("%lld\n", res);
  
  return 0;
}
