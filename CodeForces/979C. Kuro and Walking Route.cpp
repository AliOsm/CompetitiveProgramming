#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;
int n, x, y, p[N], cnt;
bool vis[N];
vector<int> path;
vector<vector<int> > g;
queue<int> q;

int BFS() {
  q.push(x);
  p[x] = x;
  vis[x] = true;

  while(!q.empty()) {
    int fr = q.front();
    q.pop();

    for(int i = 0; i < g[fr].size(); ++i) {
      if(!vis[g[fr][i]]) {
        vis[g[fr][i]] = true;
        p[g[fr][i]] = fr;
        q.push(g[fr][i]);
      }
    }
  }

  int v = y;
  path.push_back(v);
  while(v != p[v]) {
    v = p[v];
    path.push_back(v);
  }

  path.pop_back();
  return path.back();
}

void DFS(int u) {
  vis[u] = true;
  ++cnt;

  for(int i = 0; i < g[u].size(); ++i)
    if(!vis[g[u][i]])
      DFS(g[u][i]);
}

int main() {
  cin >> n >> x >> y;
  --x, --y;
  g.resize(n);
  for(int i = 0, a, b; i < n - 1; ++i) {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    swap(a, b);
    g[a].push_back(b);
  }

  int rem = BFS();

  memset(vis, false, sizeof vis);
  vis[rem] = true;
  DFS(x);

  int tmp = cnt;
  cnt = 0;

  memset(vis, false, sizeof vis);
  vis[path[1]] = true;
  DFS(y);

  cout << (1ll * n * (n - 1)) - (1ll * tmp * cnt) << endl;

  return 0;
}
