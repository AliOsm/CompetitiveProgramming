#include <bits/stdc++.h>

using namespace std;

int const N = 51;
int n, m, g[N][N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      scanf("%d", &g[i][j]);
  
  int res = 4;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if(g[i][j] == 1 && (i - 1 < 0 || i + 1 >= n || j - 1 < 0 || j + 1 >= m))
        res = 2;
  
  printf("%d\n", res);

  return 0;
}
