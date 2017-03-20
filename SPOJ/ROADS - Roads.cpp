#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int k, n, r, dp[101][10001];

struct road {
  int to, length, cost;
  
  road(int to, int length, int cost) {
    this->to = to;
    this->length = length;
    this->cost = cost;
  }
  
  bool operator<(const road &e) const {
	  return cost < e.cost;
	}
};

vector<vector<road> > g;

int calc(int node, int cost) {
  if(cost < 0) return 1e9;
  if(node == n - 1) return 0;
  
  int &res = dp[node][cost];
  if(res != -1) return res;
  res = 1e9;
  
  for(int i = 0; i < g[node].size(); i++)
    res = min(res, calc(g[node][i].to, cost - g[node][i].cost) + g[node][i].length);
  
  return res;
}

int main() {
  int kace, s, d, l, t, res;
  scanf("%d", &kace);
  
  while(kace--) {
    scanf("%d%d%d", &k, &n, &r);
    
    g.clear();
    g.resize(n);
    
    for(int i = 0; i < r; i++) {
      scanf("%d%d%d%d", &s, &d, &l, &t);
      s--; d--;
      if(s == d) continue;
      g[s].push_back(road(d, l, t));
    }
    
    memset(dp, -1, sizeof dp);
    res = calc(0, k);
    if(res == 1e9) puts("-1");
    else printf("%d\n", res);
  }
  
  return 0;
}

