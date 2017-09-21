#include <bits/stdc++.h>

using namespace std;

int n, a[1001], b[1001];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d %d", a + i, b + i);
  
  int res = 0;
  for(int i = 0, cur = 0; i < n; ++i)
    cur -= a[i], cur += b[i], res = max(res, cur);
  printf("%d\n", res);
  
  return 0;
}
