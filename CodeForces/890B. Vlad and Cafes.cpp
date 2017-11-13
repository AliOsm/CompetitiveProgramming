#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, m, q, p, x, y, a[N], lst[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  
  memset(lst, -1, sizeof lst);
  for(int i = 1; i <= n; ++i)
    lst[a[i]] = i;
  
  int idx, val = 1e9;
  for(int i = 0; i < N; ++i)
    if(lst[i] != -1 && lst[i] < val)
      val = lst[i], idx = i;
  
  printf("%d\n", idx);
  
  return 0;
}
