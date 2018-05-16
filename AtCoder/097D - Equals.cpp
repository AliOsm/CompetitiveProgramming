#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m, p[N];
bool vis[N];
vector<vector<int> > g;
vector<int> cur;

void DFS(int u) {
  vis[u] = true;
  cur.push_back(u);

  for(int i = 0; i < g[u].size(); ++i)
    if(!vis[g[u][i]])
      DFS(g[u][i]);
}

int main() {
  cin >> n >> m;
  g.resize(n);
  for(int i = 0; i < n; ++i)
    cin >> p[i], --p[i];
  for(int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    swap(a, b);
    g[a].push_back(b);
  }

  int res = 0;
  for(int i = 0; i < n; ++i) {
    if(!vis[i]) {
      DFS(i);

      sort(cur.begin(), cur.end());
      for(int j = 0; j < cur.size(); ++j)
        if(binary_search(cur.begin(), cur.end(), p[cur[j]]))
          ++res;
      cur.clear();
    }
  }

  cout << res << endl;

  return 0;
}
