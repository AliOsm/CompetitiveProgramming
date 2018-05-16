#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, m, res;
bool vis[N];
vector<vector<int> > g;
vector<int> all;

void DFS(int u) {
  vis[u] = true;
  all.push_back(u);

  for(int i = 0;i < g[u].size(); ++i)
    if(!vis[g[u][i]])
      DFS(g[u][i]);
}

int main() {
  cin >> n >> m;
  g.resize(n);
  for(int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    swap(a, b);
    g[a].push_back(b);
  }

  for(int i = 0; i < n; ++i) {
    if(!vis[i]) {
      all.clear();
      DFS(i);

      bool ok = true;
      for(int j = 0; j < all.size(); ++j)
        if(g[all[j]].size() != 2) {
          ok = false;
          break;
        }

      res += (ok && all.size() > 2);
    }
  }

  cout << res << endl;

  return 0;
}
