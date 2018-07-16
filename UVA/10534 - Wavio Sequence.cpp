/*
  Idea:
    - Using NlogN longest increasing subsequence we can obtain
      the LIS and LDS at each index `i`.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 10;
int n, a[N], t[N], seq[2][N];

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; ++i)
      scanf("%d", a + i);

    memset(seq, -1, sizeof seq);
    int l;

    for(int cnt = 0; cnt < 2; ++cnt) {
      memset(t, 0, sizeof t);
      l = 0;
      for(int i = 0, idx; i < n; ++i) {
        idx = lower_bound(t, t + l, a[i]) - t;
        t[idx] = a[i];
        if(idx == l)
          ++l;
        seq[cnt][i] = idx + 1;
      }

      reverse(a, a + n);
    }

    reverse(seq[1], seq[1] + n);

    int mx = 0;
    for(int i = 0; i < n; ++i)
      mx = max(mx, min(seq[0][i], seq[1][i]) * 2 - 1);
    printf("%d\n", mx);
  }

  return 0;
}
