/*
  Idea:
    - If anyone win the last round, then he will have more money than anyone else.
    - Using the observation in the previous point we can take the probability
      of winning the last round and drop anything else.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 1;
int n, m, a[N];

int main() {
  while(scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
    long long to = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j)
        scanf("%d", a + i);
      to += a[i];
    }

    for(int i = 0, gcd; i < n; ++i) {
      gcd = __gcd(to, 1ll * a[i]);
      printf("%d / %lld\n", a[i] / gcd, a[i] == 0 ? 1 : to / gcd);
    }
  }

  return 0;
}
