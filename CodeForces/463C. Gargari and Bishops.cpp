#include <bits/stdc++.h>

using namespace std;

int const N = 3001;
int n, g[N][N], x, y, xx, yy;
long long dp1[2 * N], dp2[2 * N], sol1 = -1, sol2 = -1;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
      scanf("%d", &g[i][j]);
      dp1[i + j] += g[i][j];
      dp2[i - j + n] += g[i][j];
    }
  
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
      long long v = dp1[i + j] + dp2[i - j + n] - g[i][j];
      if((i + j) & 1) {
        if(v > sol2) {
          sol2 = v;
          xx = i;
          yy = j;
        }
      } else {
        if(v > sol1) {
          sol1 = v;
          x = i;
          y = j;
        }
      }
    }
  
  printf("%lld\n", sol1 + sol2);
  printf("%d %d %d %d\n", x, y, xx, yy);
  
  return 0;
}
