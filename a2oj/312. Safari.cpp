#include <stdio.h>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <memory.h>

using namespace std;

int const N = 1e4 + 1, OO = 1e9;
int n, m, cost[N];
bool vis[N];
vector<vector<pair<int, int> > > g;
priority_queue<pair<int, int> > q;
bitset<N> prime;

void sieve() {
  prime.set();
  prime[0] = prime[1] = 0;
  for(int i =2; i * i < N; i++)
    if(prime[i])
      for(int j = i * i; j < N; j += i)
        prime[j] = 0;
}

void Dijkstra(int src) {
  fill(cost, cost + N, OO);
  cost[src] = 0;
  memset(vis, false, sizeof vis);
  while(!q.empty()) q.pop();
  q.push(make_pair(0, src));
  
  int size, v, c;
  while(!q.empty()) {
    size = q.size();
    
    while(size--) {
      v = q.top().second;
      c = -q.top().first;
      q.pop();
      
      if(vis[v]) continue;
      vis[v] = true;
      
      for(int i = 0; i < g[v].size(); i++)
        if(g[v][i].second + c < cost[g[v][i].first]) {
          cost[g[v][i].first] = g[v][i].second + c;
          q.push(make_pair(-cost[g[v][i].first], g[v][i].first));
        }
    }
  }
}

int main() {
  sieve();
  
  int t;
  scanf("%d", &t);
  
  int a, b, c;
  for(int cnt = 1; t--; cnt++) {
    scanf("%d%d", &n, &m);
    
    g.clear();
    g.resize(n);
    
    while(m--) {
      scanf("%d%d%d", &a, &b, &c);
      a--; b--;
      
      if(prime[c]) {
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
      }
    }
    
    scanf("%d%d", &a, &b);
    a--; b--;
    
    Dijkstra(a);
    if(cost[b] == OO) printf("Case %d: -1\n", cnt);
    else printf("Case %d: %d\n", cnt, cost[b]);
  }
  
  return 0;
}

