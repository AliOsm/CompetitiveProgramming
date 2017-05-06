#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int const N = 201;
int n, m, color[N];
vector<vector<int> > g;
queue<int> q;

bool checkBipartite(int src) {
  memset(color, -1, sizeof color);
  color[src] = 0;
  while(!q.empty()) q.pop();
  q.push(src);
  
  int size, fr;
  while(!q.empty()) {
    size = q.size();
    
    while(size-- > 0) {
      fr = q.front();
      q.pop();
      
      for(int i = 0; i < g[fr].size(); ++i) {
        if(color[g[fr][i]] == color[fr])
          return false;
        
        if(color[g[fr][i]] == -1) {
          color[g[fr][i]] = 1 - color[fr];
          q.push(g[fr][i]);
        }
      }
    }
  }
  
  return true;
}

int main() {
  while(scanf("%d", &n) && n != 0) {
    g.clear();
    g.resize(n);
    
    scanf("%d", &m);
    
    int a, b;
    while(m-- > 0) {
      scanf("%d%d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
    }
    
    if(checkBipartite(0))
      puts("BICOLORABLE.");
    else
      puts("NOT BICOLORABLE.");
  }
  
  return 0;
}

