#include <bits/stdc++.h>

using namespace std;

int const N = 51;
int n, a[N], p[5], idx;
long long sol[5], res;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0; i < 5; ++i)
    scanf("%d", p + i);

  res = 0;
  for(int i = 0; i < n; ++i) {
    res += a[i];
    while(res >= p[0]) {
      idx = upper_bound(p, p + 5, res) - p;
      --idx;
      sol[idx] += res / p[idx];
      res %= p[idx];
    }
  }

  for(int i = 0; i < 5; ++i)
    printf("%s%lld", i != 0 ? " " : "", sol[i]);
  printf("\n%lld\n", res);

  return 0;
}

