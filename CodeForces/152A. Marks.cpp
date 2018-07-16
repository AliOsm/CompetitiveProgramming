#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n, m, best[N];
char g[N][N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%s", g[i]);
  
  for(int i = 0; i < m; ++i) {
    int mx = 0;
    for(int j = 0; j < n; ++j)
      mx = max(mx, g[j][i] - '0');
    
    for(int j = 0; j < n; ++j)
      if(mx == g[j][i] - '0')
        ++best[j];
  }

  int res = 0;
  for(int i = 0; i < n; ++i)
    res += best[i] > 0;
  
  printf("%d\n", res);

  return 0;
}
