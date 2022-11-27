#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 10;
int n, m, s, e;
long long a[N], cs[N], ranges[N], ones, cnt, res[N];

int main() {
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }

  while (m-- != 0) {
    scanf("%d %d", &s, &e);
    cs[s] += 1;
    cs[e + 1] -= 1;
    ranges[e + 1] += e - s + 1;
  }
  
  for(int i = 1; i <= n; ++i) {
    ones += cs[i];
    cnt -= ranges[i];
    cnt += ones;
    
    res[i] = a[i] + cnt;
  }

  for(int i = 1; i <= n; ++i) {
    printf("%lld ", res[i]);
  }
  puts("");
  
  return 0;
}
