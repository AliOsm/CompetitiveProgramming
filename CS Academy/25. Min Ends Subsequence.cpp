/*
  Idea:
    - Segment tree.
    - Try each element with the maximum element after it
      and count the number of elements between them less
      than the current element.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N], mx[N];
vector<int> seg[4 * N];

void build(int at, int l, int r) {
  if(l == r) {
    seg[at].push_back(a[l]);
    return;
  }
  
  int mid = (l + r) >> 1;
  build(at << 1, l, mid);
  build(at << 1 | 1, mid + 1, r);
  
  int i = 0, j = 0;
  for(; i < seg[at << 1].size() && j < seg[at << 1 | 1].size();)
    if(seg[at << 1][i] < seg[at << 1 | 1][j])
      seg[at].push_back(seg[at << 1][i++]);
    else
      seg[at].push_back(seg[at << 1 | 1][j++]);
  while(i < seg[at << 1].size())
    seg[at].push_back(seg[at << 1][i++]);
  while(j < seg[at << 1 | 1].size())
    seg[at].push_back(seg[at << 1 | 1][j++]);
}

int s, e, tar;
int get(int at, int l, int r) {
  if(l > e || r < s)
    return 0;
  
  if(l >= s && r <= e)
    return upper_bound(seg[at].begin(), seg[at].end(), tar) - seg[at].begin();
  
  int mid = (l + r) >> 1;
  return get(at << 1, l, mid) + get(at << 1 | 1, mid + 1, r);
}

int solve() {
  memset(mx, -1, sizeof mx);
  for(int i = n, cur = 1; i > 0; --i)
    while(cur <= a[i])
      mx[cur++] = i;
  
  for(int i = 0; i < 4 * N; ++i)
    seg[i].clear();
  build(1, 1, n);
  
  int ret = 0;
  for(int i = 1; i <= n; ++i) {
    s = i, e = mx[a[i]], tar = a[i];
    ret = max(ret, get(1, 1, n) + 1);
  }
  
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  
  if(n == 1) {
    puts("1");
    return 0;
  }
  
  int r1 = solve();
  reverse(a + 1, a + n + 1);
  int r2 = solve();
  printf("%d\n", max(r1, r2));
  
  return 0;
}
