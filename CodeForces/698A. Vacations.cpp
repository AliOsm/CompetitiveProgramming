#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, m, q, k, a[N], dp[N][6];

int rec(int idx, int lst) {
  if(idx == n)
    return 0;
  
  int &ret = dp[idx][lst];
  if(ret != -1)
    return ret;
  ret = 0;
  
  if(a[idx] != 0) {
    if(a[idx] == 3)
      ret = min((1 == lst) + rec(idx + 1, 1), (2 == lst) + rec(idx + 1, 2));
    else if(a[idx] == lst)
      ret = min(1 + rec(idx + 1, 3), 1 + rec(idx + 1, a[idx]));
    else
      ret = min(1 + rec(idx + 1, 3), rec(idx + 1, a[idx]));
  } else
    ret = 1 + rec(idx + 1, a[idx]);
  
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  
  memset(dp, -1, sizeof dp);
  cout << rec(0, 0) << endl;
  
  return 0;
}
