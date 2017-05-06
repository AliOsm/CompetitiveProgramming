#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int const N = 501;
int n, m, match[N];
bool grid[N][N], vis[N];

bool findMatch(int i) {
  vis[i] = true;
  
  for(int j = 0; j < m; ++j)
    if(grid[i][j] && (match[j] == -1 || (!vis[match[j]] && findMatch(match[j])))) {
      match[j] = i;
      return true;
    }
  
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  
  int res;
  for(int kase = 1; t--; ++kase) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        scanf("%d", &grid[i][j]);
    
    memset(match, -1, sizeof match);
    res = 0;
    for(int i = 0; i < n; ++i) {
      memset(vis, false, sizeof vis);
      if(findMatch(i))
        res++;
    }
    
    printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", kase, res);
  }
  
  return 0;
}

