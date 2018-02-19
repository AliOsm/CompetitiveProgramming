#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, m, a, b, fr;
long long c, tik[N], cost[N];
bool vis[N];
vector<vector<pair<int, long long> > > g;
priority_queue<pair<long long, int> > pq;

void Dijkstra() {
  for(int i = 0; i < n; ++i) {
    pq.push(make_pair(-tik[i], i));
    cost[i] = tik[i];
  }
  
  int size;
  while(!pq.empty()) {
    size = pq.size();
    
    while(size-- != 0) {
      fr = pq.top().second;
      c = -pq.top().first;
      pq.pop();
      
      if(vis[fr])
        continue;
      vis[fr] = true;
      
      for(int i = 0; i < g[fr].size(); ++i) {
        if(g[fr][i].second + c < cost[g[fr][i].first]) {
          cost[g[fr][i].first] = g[fr][i].second + c;
          pq.push(make_pair(-cost[g[fr][i].first], g[fr][i].first));
        }
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  g.resize(n);
  
  for(int i = 0; i < m; ++i) {
    scanf("%d %d %lld", &a, &b, &c);
    --a, --b;
    g[a].push_back(make_pair(b, c * 2));
    g[b].push_back(make_pair(a, c * 2));
  }
  
  for(int i = 0; i < n; ++i)
    scanf("%lld", tik + i);
  
  Dijkstra();
  
  for(int i = 0; i < n; ++i)
    printf("%s%lld", i ? " " : "", cost[i]);
  
  return 0;
}
