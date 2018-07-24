/*
  Idea:
    - Conditional probability:
      P(A | B) = P(A intersect B) / P(B)
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 21;
int n, r;
double a[N], b[N];

int main() {
  int kase = 1;
  while(scanf("%d %d", &n, &r) && (n != 0 || r  != 0)) {
    for(int i = 0; i < n; ++i)
      b[i] = 0;
    double all = 0;

    for(int i = 0; i < n; ++i)
      scanf("%lf", a + i);

    for(int i = 0; i <= ((1 << n) - 1); ++i) {
      if(__builtin_popcount(i) != r)
        continue;

      double cur = 1;
      for(int j = 0; j < n; ++j)
        if((i >> j) & 1)
          cur *= 1.0 * a[j];
        else
          cur *= (1.0 - a[j]);

      all += cur;

      for(int j = 0; j < n; ++j)
        if((i >> j) & 1)
          b[j] += cur;
    }

    printf("Case %d:\n", kase++);
    for(int i = 0; i < n; ++i) {
      printf("%0.6lf\n", b[i] / all);
    }
  }

  return 0;
}
