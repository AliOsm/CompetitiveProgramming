#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int const N = 1e5 + 1;
int x, grid[10][N], dp[10][N];

int calc(int at, int i) {
  if(i == x)
    if(at == 9) return 0;
    else return 1e9 + 1;
  
  int &res = dp[at][i];
  if(res != -1) return res;
  res = 1e9 + 1;
  
  if(at > 0) res = min(res, calc(at - 1, i + 1) + 60);
  if(at < 9) res = min(res, calc(at + 1, i + 1) + 20);
  res = min(res, calc(at, i + 1) + 30);
  
  return res -= grid[at][i];
}

int main() {
  int t;
  scanf("%d", &t);
  
  while(t-- != 0) {
    x = 0;
    scanf("%d", &x);
    x /= 100;
    
    for(int i = 0; i < 10; ++i)
      for(int j = 0; j < x; ++j)
        scanf("%d", &grid[i][j]);
    
    memset(dp, -1, sizeof dp);
    printf("%d\n\n", calc(9, 0));
  }
  
  return 0;
}

