#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, m, a[N];
vector<vector<pair<int, int> > > g;

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

long long DFS(int u, int p, int l, int r) {
  int cur = 0, all = r - l + 1;
  long long ret = 0;

  for(int i = 0, v, c, idx; i < g[u].size(); ++i) {
    v = g[u][i].first;
    c = g[u][i].second;

    if(v == p)
      continue;

    idx = upper_bound(a + l, a + r + 1, c) - a;
    cur += r - idx + 1;
    ret += DFS(v, u, idx, r);
    r = idx - 1;
  }

  return ret + 1ll * (all - cur) * (u + 1);
}

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);
    g.clear();
    g.resize(n);
    for(int i = 0, a, b, c; i < n - 1; ++i) {
      scanf("%d %d %d", &a, &b, &c);
      --a, --b;
      g[a].push_back(make_pair(b, c));
      swap(a, b);
      g[a].push_back(make_pair(b, c));
    }
    for(int i = 0; i < m; ++i)
      scanf("%d", a + i);
    for(int i = 0; i < n; ++i)
      sort(g[i].begin(), g[i].end(), cmp);
    sort(a, a + m);

    printf("%lld\n", DFS(0, -1, 0, m - 1));
  }

  return 0;
}
