#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, a[N], powers[32];

int main() {
  for(int i = 0; i < 32; ++i)
    powers[i] = 1 << i;

  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  sort(a, a + n);

  int res = 0;
  for(int i = 0; i < n; ++i) {
    bool ok = false;
    for(int j = 0; j < 32; ++j)
      if(powers[j] > a[i]) {
        int idx = lower_bound(a, a + n, powers[j] - a[i]) - a;
        if(a[idx] + a[i] == powers[j])
          if(idx != i || (idx + 1 < n && a[idx + 1] == a[idx])) {
            ok = true;
            break;
          }
      }
    res += !ok;
  }

  printf("%d\n", res);

  return 0;
}
