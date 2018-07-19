/*
  Idea:
    - DFS Order.
    - Using DFS we can construct the DFS order array and find
      the size of each subtree.
    - Using the information in the previous point we can solve each
      query.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
bool vis[N];
int n, q, idx[N], siz[N];
vector<int> ord;
vector<vector<int> > g;

int DFS(int u) {
  vis[u] = true;
  idx[u + 1] = ord.size();
  ord.push_back(u + 1);

  int ret = 1;
  for(int i = 0; i < g[u].size(); ++i)
    if(!vis[g[u][i]])
      ret += DFS(g[u][i]);
  
  return siz[u + 1] = ret;
}

int main() {
  scanf("%d %d", &n, &q);
  g.resize(n);
  for(int i = 1, a; i < n; ++i) {
    scanf("%d", &a);
    --a;
    g[a].push_back(i);
  }

  for(int i = 0; i < n; ++i)
    sort(g[i].begin(), g[i].end());

  DFS(0);

  while(q-- != 0) {
    int u, k;
    scanf("%d %d", &u, &k);

    if(idx[u] + siz[u] < idx[u] + k)
      puts("-1");
    else
      printf("%d\n", ord[idx[u] + k - 1]);
  }

  return 0;
}
