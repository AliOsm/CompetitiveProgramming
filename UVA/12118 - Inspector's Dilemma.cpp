#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int n, m, v, ds[N], odds[N];
bool odd_degree[N], vis[N];

int find(int x) {
  return ds[x] == x ? x : ds[x] = find(ds[x]);
}

int main() {
  int kase = 1;
  while(scanf("%d %d %d", &n, &m, &v) && n != 0) {
    printf("Case %d: ", kase++);
    for(int i = 0; i < n; ++i)
      ds[i] = i, odd_degree[i] = vis[i] = false, odds[i] = 0;

    for(int i = 0, a, b; i < m; ++i) {
      scanf("%d %d", &a, &b);
      --a, --b;
      vis[a] = vis[b] = true;

      odd_degree[a] = !odd_degree[a];
      odd_degree[b] = !odd_degree[b];

      ds[find(a)] = find(b);
    }

    int comp = 0;
    for(int i = 0; i < n; ++i) {
      if(!vis[i])
        continue;

      if(ds[i] == i)
        ++comp;

      if(odd_degree[i])
        ++odds[find(i)];
    }

    int res = 0;
    for(int i = 0; i < n; ++i)
      res += max(0, odds[i] / 2 - 1);

    printf("%d\n", max(0, (res + m + comp - 1)) * v);
  }

  return 0;
}
