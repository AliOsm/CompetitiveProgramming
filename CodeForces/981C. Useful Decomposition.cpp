/*
  Idea:
    - Greedy, there is a solution if and only if the tree is a single path
      or there is one node has more than two edges go from it to another nodes.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n;
bool vis[N];
vector<vector<int> > g;
vector<int> sol;

void DFS(int u) {
  vis[u] = true;

  bool ok = false;
  for(int i = 0, v; i < g[u].size(); ++i) {
    v = g[u][i];
    if(!vis[v]) {
      ok = true;
      DFS(v);
    }
  }

  if(!ok)
    sol.push_back(u + 1);
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

  int gt2 = 0;
  for(int i = 0; i < n; ++i)
    if(g[i].size() > 2)
      ++gt2;

  if(gt2 > 1) {
    puts("No");
    return 0;
  }

  puts("Yes");

  if(gt2 == 0) {
    puts("1");
    for(int i = 0; i < g.size(); ++i)
      if(g[i].size() == 1)
        printf("%d ", i + 1);
    puts("");
    return 0;
  }

  int mx = 0, idx;
  for(int i = 0; i < n; ++i) {
    if(g[i].size() > mx) {
      mx = g[i].size();
      idx = i;
    }
  }

  printf("%d\n", mx);

  DFS(idx);
  ++idx;

  for(int i = 0; i < sol.size(); ++i)
    printf("%d %d\n", idx, sol[i]);

  return 0;
}
