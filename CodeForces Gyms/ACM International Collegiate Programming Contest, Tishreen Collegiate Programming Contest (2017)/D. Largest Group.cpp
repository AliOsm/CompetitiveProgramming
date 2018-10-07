#include <bits/stdc++.h>

using namespace std;

int const N = 20;
int t, p, n, msk[N];

int main() {
  scanf("%d", &t);
  while(t--) {
    memset(msk, 0, sizeof msk);
    
    scanf("%d %d", &p, &n);
    for(int i = 0, a, b; i < n; ++i) {
      scanf("%d %d", &a, &b);
      --a, --b;
      msk[a] |= (1 << b);
    }

    int res = 0;
    for(int i = 0, And; i < (1 << p); ++i) {
      And = (1 << p) - 1;
      for(int j = 0; j < p; ++j)
        if(((i >> j) & 1) == 1)
          And &= msk[j];
      res = max(res, __builtin_popcount(i) + __builtin_popcount(And));
    }

    printf("%d\n", res);
  }

  return 0;
}
