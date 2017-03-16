#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
  int from, to, cost;
  bool operator<(const edge &e) const {
    return cost < e.cost;
  }
};

int const N = 2e5;
int n, m, ds[N];
vector<edge> e;

int find(int x) {
  return (ds[x] == x ? x : ds[x] = find(ds[x]));
}

int main() {
  int u, v, res, take;
  
  while(cin >> n >> m && n && m) {
    res = take = 0;
    
    for(int i = 0; i < n; i++)
      ds[i] = i;
    
    e.clear();
    e.resize(m);
    
    for(int i = 0; i < m; i++) {
      cin >> e[i].from >> e[i].to >> e[i].cost;
      res += e[i].cost;
    }
    sort(e.begin(), e.end());
    
    for(int i = 0; i < m && take < n - 1; i++) {
      u = find(e[i].from);
      v = find(e[i].to);
      
      if(u != v) {
        take++;
        ds[u] = v;
        res -= e[i].cost;
      }
    }
    
    cout << res << endl;
  }

  return 0;
}

