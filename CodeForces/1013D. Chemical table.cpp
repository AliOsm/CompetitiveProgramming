/*
  Idea:
    - http://codeforces.com/blog/entry/60920
*/

#include <bits/stdc++.h>

using namespace std;

bool vis[int(4e5 + 1)];
int n, m, q;
vector<vector<int> > g;

void DFS(int u) {
  vis[u] = true;
  for(int i = 0; i < g[u].size(); ++i)
    if(!vis[g[u][i]])
      DFS(g[u][i]);
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  g.resize(n + m);
  for(int i = 0, a, b; i < q; ++i) {
    scanf("%d %d", &a, &b);
    --a, --b;
    g[a].push_back(b + n);
    swap(a, b);
    g[a + n].push_back(b);
  }

  int comp = 0;
  for(int i = 0; i < n + m; ++i) {
    if(vis[i])
      continue;
    ++comp;
    DFS(i);
  }

  printf("%d\n", comp - 1);

  return 0;
}
