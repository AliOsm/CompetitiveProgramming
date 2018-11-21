/*
  Idea:
    - Segment Tree.
    - In the beginning each element `x` equal to its value,
      and after each query the element with value `x` will
      change to be equal to `y`.
    - To maintain the previous effect we can use any data
      structure like Segment Tree, each node in the segment
      tree contains the mapping between the real values and
      the current values.
    - We should use lazy propagation to pass the time limit.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1, M = 1e2 + 1;
int n, q, s, e, x, y, tar, a[N], seg[4 * N][M], lazy[4 * N];

void build(int at, int l, int r) {
  for(int i = 1; i < M; ++i)
    seg[at][i] = i;

  if(l == r)
    return;

  int mid = (l + r) >> 1;
  build(at << 1, l, mid);
  build(at << 1 | 1, mid + 1, r);
}

void pro(int at, int l, int r) {
  if(l != r) {
    lazy[at << 1] = lazy[at << 1 | 1] = 1;

    for(int i = 1; i < M; ++i)
      seg[at << 1][i] = seg[at][seg[at << 1][i]],
      seg[at << 1 | 1][i] = seg[at][seg[at << 1 | 1][i]];

    lazy[at] = 0;
    for(int i = 1; i < M; ++i)
      seg[at][i] = i;
  }
}

void update(int at, int l, int r) {
  if(lazy[at] != 0)
    pro(at, l, r);

  if(l > e || r < s)
    return;

  if(l >= s && r <= e) {
    lazy[at] = 1;
    for(int i = 1; i < M; ++i)
      if(seg[at][i] == x)
        seg[at][i] = y;
    pro(at, l, r);
    return;
  }

  int mid = (l + r) >> 1;
  update(at << 1, l, mid);
  update(at << 1 | 1, mid + 1, r);
}

int get(int at, int l, int r) {
  if(lazy[at] != 0)
    pro(at, l, r);

  if(l > e || r < s)
    return 0;

  if(l >= s && r <= e)
    return seg[at][tar];

  int mid = (l + r) >> 1;
  return get(at << 1, l, mid) + get(at << 1 | 1, mid + 1, r);
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", a + i);

  build(1, 1, n);

  scanf("%d", &q);
  for(int i = 0; i < q; ++i) {
    scanf("%d %d %d %d", &s, &e, &x, &y);
    update(1, 1, n);
  }

  for(int i = 1; i <= n; ++i) {
    s = e = i;
    tar = a[i];
    printf("%s%d", i == 1 ? "" : " ", get(1, 1, n));
  }
  puts("");

  return 0;
}
