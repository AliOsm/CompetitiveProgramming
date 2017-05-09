#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n, m, grid[11][101], dp[11][101][101];

int calc(int i, int j, int t) {
  if(t > m)
    return -1e5 - 1;
  
  if(i == n)
    return 0;
  
  int &res = dp[i][j][t];
  if(res != -1) return res;
  res = -1e5 - 1;
  
  if(grid[i][j] >= 5)
    res = max(res, calc(i + 1, 0, t + j + 1) + grid[i][j]);
  
  if(j < m - 1)
    res = max(res, calc(i, j + 1, t));
  
  return res;
}

int main() {
  int t;
  scanf("%d", &t);
  
  double res;
  while(t-- != 0) {
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j) {
        scanf("%d", &grid[i][j]);
        
        for(int k = 0; k < 101; ++k)
          dp[i][j][k] = -1;
      }
    
    res = calc(0, 0, 0);
    if(res < 0)
      puts("Peter, you shouldn\'t have played billiard that much.");
    else {
      res = (res = round(res = res / n * 100.0)) / 100;
      printf("Maximal possible average mark - %.2lf.\n", res);
    }
  }
  
  return 0;
}

