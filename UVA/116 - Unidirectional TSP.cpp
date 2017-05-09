#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int m, n, grid[11][101], dp[11][101];

int calc(int i, int j) {
  if(j == n)
    return 0;
  
  int &res = dp[i][j];
  if(res != -2e9 - 1) return res;
  res = 2e9 + 1;
  
  if(i == 0)
    res = min(res, calc(m - 1, j + 1));
  else
    res = min(res, calc(i - 1, j + 1));
  
  res = min(res, calc(i, j + 1));
  
  if(i == m - 1)
    res = min(res, calc(0, j + 1));
  else
    res = min(res, calc(i + 1, j + 1));
  
  return res += grid[i][j];
}

void path(int i, int j) {
  if(j == n)
    return;
  
  if(j != 0 && j != n) putchar(' ');
  printf("%d", i + 1);
  
  int triv = calc(i, j) - grid[i][j];
  
  if(i == m - 1 && triv == calc(0, j + 1))
    path(0, j + 1);
  else if(i != 0 && triv == calc(i - 1, j + 1))
    path(i - 1, j + 1);
  else if(triv == calc(i, j + 1))
    path(i, j + 1);
  else if(triv == calc(i + 1, j + 1))
    path(i + 1, j + 1);
  else if(i == 0 && triv == calc(m - 1, j + 1))
    path(m - 1, j + 1);
}

int main() {
  int res, index;
  while(scanf("%d%d", &m, &n) != EOF) {
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j) {
        scanf("%d", &grid[i][j]);
        dp[i][j] = -2e9 - 1;
      }
    
    res = 2e9 + 1;
    for(int i = 0; i < m; ++i)
      if(res > calc(i, 0)) {
        res = calc(i, 0);
        index = i;
      }
    
    path(index, 0);
    putchar('\n');
    printf("%d\n", res);
  }
  
  return 0;
}

