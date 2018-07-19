/*
  Idea:
    - Binary search on `k`.
    - In check function we can do topological sort to check if
      there is a valid skills order.
    - At anytime if there is more than 1 node in the priority queue
      then there is no valid skills order.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m, in[N];
priority_queue<int> pq;
vector<pair<int, int> > edges;
vector<vector<int> > g;

bool can(int mid) {
  while(!pq.empty())
    pq.pop();

  memset(in, 0, sizeof in);
  g.clear();
  g.resize(n);
  for(int i = 0; i < mid; ++i) {
    ++in[edges[i].second];
    g[edges[i].first].push_back(edges[i].second);
  }

  for(int i = 0; i < n; ++i)
    if(in[i] == 0) {
      pq.push(i);
      if(pq.size() > 1)
        return false;
    }

  while(!pq.empty()) {
    int u = pq.top();
    pq.pop();

    for(int i = 0; i < g[u].size(); ++i)
      if(--in[g[u][i]] == 0)
        pq.push(g[u][i]);

    if(pq.size() > 1)
      return false;
  }

  return true;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0, a, b; i < m; ++i) {
    scanf("%d %d", &a, &b);
    --a, --b;
    edges.push_back({a, b});
  }

  int l = 1, r = m, mid, res = -1;
  while(l <= r) {
    mid = (l + r) >> 1;
    if(can(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }

  printf("%d\n", res);

  return 0;
}
