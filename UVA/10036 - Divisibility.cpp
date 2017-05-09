#include <stdio.h>
#include <memory.h>

int const N = 1e4 + 1;
int n, k, a[N], dp[N][100];

int fix(int x) {
  return (x % k - k) + k;
}

bool calc(int i, int mod) {
  if(i == n)
    return mod == 0;
  
  int &res = dp[i][mod];
  if(res != -1) return res;
  res = 0;
  
  return res = calc(i + 1, fix(mod + a[i])) || calc(i + 1, fix(mod - a[i]));
}

int main() {
  int t;
  scanf("%d", &t);
  
  while(t-- != 0) {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i)
      scanf("%d", a + i);
    
    memset(dp, -1, sizeof dp);
    if(calc(1, fix(a[0])))
      puts("Divisible");
    else
      puts("Not divisible");
  }
  
  return 0;
}

