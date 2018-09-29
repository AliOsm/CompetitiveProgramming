#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m, a[N];
long long t = 0;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  
  sort(a, a + n);
  for(int i = 0, cur; i < n; ++i) {
    cur = 0;
    while(i < n && a[i] <= m)
      t += a[i], ++cur, ++i;
    --i;
    m += cur;
    if(cur == 0)
      break;
  }
  
  printf("%lld\n", (1ll * m * (m + 1)) / 2 - t);
  
  return 0;
}
