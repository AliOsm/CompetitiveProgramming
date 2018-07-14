#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int n, m, c[N], a[N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d", c + i);
  for(int i = 0; i < m; ++i)
    scanf("%d", a + i);

  int res = 0;
  for(int i = 0, cur = 0; i < n; ++i) {
    if(a[cur] >= c[i])
      ++cur, ++res;
    if(cur >= m)
      break;
  }

  printf("%d\n", res);

  return 0;
}
