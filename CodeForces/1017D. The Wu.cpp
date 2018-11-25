/*
  Idea:
    - Precalculate the frequency of each element in the multiset S.
    - Precalculate the cost of each mask from 0 to 2^n.
    - Precalculate the number of elements for each pair (i, j)
      that has `k` as cost.
    - Prefix sum the previous point.
    - Answer the queries in O(n).
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 12;
char s[13];
int n, m, q, k, a[N], c[1 << N], fr[1 << N], all[1 << N][1201];

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0, tmp; i < m; ++i) {
    scanf("%s", s);
    tmp = 0;
    for(int j = 0; j < n; ++j)
      tmp |= ((s[j] - '0') << (n - j - 1));
    ++fr[tmp];
  }

  for(int i = 0; i < (1 << n); ++i)
    for(int j = 0; j < n; ++j)
      if(((i >> j) & 1) != 0)
        c[i] += a[n - j - 1];

  for(int i = 0; i < (1 << n); ++i)
    for(int j = 0, x; j < (1 << n); ++j) {
      x = 0;
      for(int l = 0; l < n; ++l)
        if(((i >> l) & 1) == ((j >> l) & 1))
          x |= (1 << l);

      all[i][c[x]] += fr[j];
    }

  for(int i = 0; i < (1 << n); ++i)
    for(int j = 1; j < 1201; ++j)
      all[i][j] += all[i][j - 1];

  for(int i = 0, cur; i < q; ++i) {
    scanf("%s %d", s, &k);
    cur = 0;
    for(int j = 0; j < n; ++j)
      cur |= ((s[j] - '0') << (n - j - 1));
    printf("%d\n", all[cur][k]);
  }

  return 0;
}
