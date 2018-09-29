#include <bits/stdc++.h>

using namespace std;

int n, c, s, a[5], b[5], dp[100001][200];

int rec(int cok, int msk, int add) {
  if(cok >= c)
    return 0;
  
  int &ret = dp[cok][msk];
  if(ret != -1)
    return ret;
  ret = 1e9;
  
  ret = min(ret, rec(cok + s + add, msk, add) + 1);
  
  for(int i = 0; i < n; ++i)
    if(((msk >> i) & 1) == 0 && cok >= a[i]) {
      ret = min(ret, rec(cok - a[i] + s, msk | (1 << i), add + b[i]) + 1);
      ret = min(ret, rec(cok - a[i], msk | (1 << i), add + b[i]));
    }
  
  return ret;
}

int main() {
  scanf("%d %d %d", &n, &c ,&s);
  for(int i = 0; i < n; ++i)
    scanf("%d %d", a + i, b + i);
  
  memset(dp, -1, sizeof dp);
  printf("%d\n", rec(0, 0, 0));
  
  return 0;
}
