/*
  Idea:
    - Segment tree.
    - Calculate the segment of each query based on the information
      in the array `a`.
    - Using Segment tree with Lazy propagation we can do the queries
      from 1 to `q`.
    - After the end of the queries for each 0 element in the array
      we can put the value of the first non-zero element after of before
      it instead of it.
    - Finally, we need to check if the array contains at least 1 element
      equals to `q`, if not we need to change the value of 0 element index
      to `q` to make sure that we can perform all queries.
*/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int const N = 2e5 + 10;
int n, q, a[N], b[N], seg[4 * N], lazy[4 * N];
pair<int, int> ss[N];

void pro(int at, int l, int r) {
  seg[at] = lazy[at];
  if(l != r) {
    lazy[at << 1] = lazy[at];
    lazy[at << 1 | 1] = lazy[at];
  }
  lazy[at] = 0;
}

int s, e, v;
void update(int at, int l, int r) {
  if(lazy[at] != 0)
    pro(at, l, r);

  if(s > r || e < l)
    return;

  if(l >= s && r <= e) {
    lazy[at] = v;
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

  if(l >= s && r <= e)
    return seg[at];

  int mid = (l + r) >> 1;
  if(s >= l && s <= mid)
    return get(at << 1, l, mid);
  else
    return get(at << 1 | 1, mid + 1, r);
}

int get(int i, int d) {
  if(d == 1) {
    for(int j = i; j <= n; ++j)
      if(b[j] != 0)
        return b[j];
    return -1;
  } else {
    for(int j = i; j >= 1; --j)
      if(b[j] != 0)
        return b[j];
    return q;
  }
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if(ss[a[i]].F == 0)
      ss[a[i]].F = i;
    ss[a[i]].S = i;
  }

  for(int i = 1; i <= q; ++i) {
    if(ss[i].F == 0)
      continue;
    s = ss[i].F, e = ss[i].S, v = i;
    update(1, 1, n);
  }

  for(int i = 1; i <= n; ++i) {
    s = i, e = i;
    b[i] = get(1, 1, n);
  }

  for(int i = 1; i <= n; ++i)
    if(a[i] != b[i] && a[i] != 0) {
      puts("NO");
      return 0;
    }

  for(int i = 1; i <= n; ++i)
    if(b[i] == 0) {
      int cur = get(i + 1, 1);
      if(cur == -1)
        cur = get(i - 1, 2);
      while(b[i] == 0)
        b[i++] = cur;
      --i;
    }

  bool ok = false;
  for(int i = 1; i <= n; ++i)
    if(b[i] == q) {
      ok = true;
      break;
    }

  if(!ok) {
    for(int i = 1; i <= n; ++i)
      if(a[i] == 0) {
        b[i] = q;
        ok = true;
        break;
      }
  }

  if(!ok) {
    puts("NO");
    return 0;
  }

  puts("YES");
  for(int i = 1; i <= n; ++i)
    printf("%s%d", i == 1 ? "" : " ", b[i]);
  puts("");

  return 0;
}
