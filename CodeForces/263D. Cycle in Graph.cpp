#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n, m, k;
bool vis[N];
vector<vector<int> > g;
vector<int> sol;

void DFS(int v, int src) {
  vis[v] = true;
  sol.push_back(v);
  
  for(int i = 0; i < (int)g[v].size(); ++i) {
    int u = g[v][i];
    if(u == src && sol.size() >= k + 1) {
      printf("%d\n", (int)sol.size());
      for(int j = 0; j < (int)sol.size(); ++j)
        printf("%d ", sol[j]);
      puts("");
      exit(0);
    }
    if(!vis[u])
      DFS(u, src);
  }
  
  sol.pop_back();
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  g.resize(n + 10);
  for(int i = 0, a, b; i < m; ++i) {
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    swap(a, b);
    g[a].push_back(b);
  }
  for(int i = 0; i < (int)g.size(); ++i)
    sort(g[i].begin(), g[i].end());
  
  for(int i = 1; i < n; ++i) {
    memset(vis, false, sizeof vis);
    DFS(i, i);
  }
  
  return 0;
}
