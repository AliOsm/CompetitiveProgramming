/*
  Idea:
    - Segment tree and BFS.
    - Precalculate the indexes of each number in array `a`.
    - Start with range `(1, n)`.
    - Find the minimum number in it (Segment tree).
    - Split the current segment to smaller segments and push them
      to the queue (BFS) based on the positions of the minimum
      number in the current segment.
    - Repeat the procedure for the other segments until the queue
      is empty.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, s, e, val, a[N], seg[N * 4];
vector<pair<int, int> > sol;
queue<pair<pair<int, int>, int> > q;
vector<vector<int> > pos;

void build(int at, int l, int r) {
  if(l == r) {
    seg[at] = a[l];
    return;
  }

  int mid = (l + r) >> 1;
  build(at << 1, l, mid);
  build(at << 1 | 1, mid + 1, r);
  seg[at] = min(seg[at << 1], seg[at << 1 | 1]);
}

int get(int at, int l, int r) {
  if(l > e || r < s)
    return 1e9;

  if(l >= s && r <= e)
    return seg[at];

  int mid = (l + r) >> 1;
  return min(get(at << 1, l, mid), get(at << 1 | 1, mid + 1, r));
}

int main() {
  pos.resize(N);

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    pos[a[i]].push_back(i);
  }

  build(1, 1, n);

  q.push({{1, n}, 0});
  while(!q.empty()) {
    int l = q.front().first.first, r = q.front().first.second;
    int cur = q.front().second;
    q.pop();

    if(!(l <= r))
      continue;

    s = l, e = r;
    int mn = get(1, 1, n);

    for(int i = 0; i < mn - cur; ++i)
      sol.push_back({l, r});

    int idx = lower_bound(pos[mn].begin(), pos[mn].end(), l) - pos[mn].begin();

    q.push({{l, pos[mn][idx] - 1}, (mn - cur) + cur});
    ++idx;
    while(idx < pos[mn].size() && pos[mn][idx] <= r) {
      q.push({{pos[mn][idx - 1] + 1, pos[mn][idx] - 1}, (mn - cur) + cur});
      ++idx;
    }

    --idx;
    q.push({{pos[mn][idx] + 1, r}, (mn - cur) + cur});
  }

  printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
    printf("%d %d\n", sol[i].first, sol[i].second);

  return 0;
}
