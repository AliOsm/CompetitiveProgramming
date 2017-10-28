#include <bits/stdc++.h>
 
using namespace std;
 
int const N = 5e4 + 1;
int n , m , p , match[N], vis[N];
vector<int> g[N];
 
bool findMatch(int v, int id) {
  vis[v] = id;
  
  random_shuffle(g[v].begin(), g[v].end());
  
  for(int i = 0, u; i < (int)g[v].size(); ++i) {
    u = g[v][i];
    if(match[u] == -1) {
      match[u] = v;
      return true;
    }
  }
  
  for(int i = 0, u; i < (int)g[v].size(); ++i) {
    u = g[v][i];
    if(vis[match[u]] != id && findMatch(match[u], id)) {
      match[u] = v;
      return true;
    }
  }
  
  return false;
}
 
int main() {
  srand(time(NULL));
  scanf("%d%d%d", &n , &m , &p);
  int x , y;
  
  for(int i = 0; i < p; ++i) {
    scanf("%d%d" , &x , &y);
    g[--x].push_back(--y);
  }
  
  for(int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
    g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
  }
  
  memset(match, -1, sizeof match);
  memset(vis, -1, sizeof vis);
  int res = 0;
  for(int i = 0; i < n; ++i)
    if(findMatch(i, i))
      ++res;
  
  printf("%d\n", res);
  
  return 0;
} 
