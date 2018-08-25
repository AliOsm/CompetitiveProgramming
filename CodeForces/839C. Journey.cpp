/*
  Idea:
    - DFS and calculate the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
bool vis[N];
int n;
vector<vector<int> > g;

double rec(int u, int p) {
  vis[u] = true;

  double ret = 0, prop = 1.0 / (g[u].size() - (p != -1));
  for(int i = 0, v; i < g[u].size(); ++i) {
    v = g[u][i];

    if(!vis[v])
      ret += (rec(v, u) + 1) * prop;
  }

  return ret;
}

int main() {
  scanf("%d", &n);
  g.resize(n);
  for(int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d %d", &a, &b);
    --a, --b;
    g[a].push_back(b);
    swap(a, b);
    g[a].push_back(b);
  }

  printf("%.10lf\n", rec(0, -1));

  return 0;
}
