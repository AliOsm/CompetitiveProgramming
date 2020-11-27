#include <bits/stdc++.h>
 
using namespace std;
 
int const N = 1e2 + 1;
int n, m;
char g[N][N];
 
int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%s", g[i]);
  
  bool cur = true;
  for(int i = 0; i < n; ++i) {
    if(m % 2 == 0)
      cur = !cur;
    for(int j = 0; j < m; ++j) {
      if(cur && g[i][j] != '-')
        g[i][j] = 'W';
      else if(!cur && g[i][j] != '-')
        g[i][j] = 'B';
      cur = !cur;
    }
  }
  
  for(int i = 0; i < n; ++i)
    puts(g[i]);
 
  return 0;
}
