/*
  Idea:
    - Using segment tree and two pointers we can track the maximum number of
      repetitions in the current subarray.
    - Each time the maximum number of repetitions reach value greater than or
      equal to `k`, then add `n - r` to the answer and try to leave the left
      element in the current subarray.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 4e5 + 1;
int n, k, a[N], seg[4 * N], tar, val;
vector<int> all;

void update(int at, int l, int r) {
  if(l == r) {
    seg[at] += val;
    return;
  }

  int mid = (l + r) >> 1;

  if(mid > tar)
    update(at << 1, l, mid);
  else
    update(at << 1 | 1, mid + 1, r);

  seg[at] = max(seg[at << 1], seg[at << 1 | 1]);
}

int get(int at, int l, int r) {
  if(l == r)
    return seg[at];

  int mid = (l + r) >> 1;

  if(mid > tar)
    return get(at << 1, l, mid);
  else
    return get(at << 1 | 1, mid + 1, r);
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    all.push_back(a[i]);
  }

  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());

  for(int i = 0; i < n; ++i)
    a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();

  long long res = 0;
  int l = 0, r = 0;
  while(r < n) {
    tar = a[r];
    val = 1;
    update(1, 1, n);
    int tmp = seg[1];

    while(tmp >= k) {
      res += n - r;
      tar = a[l++];
      val = -1;
      update(1, 1, n);
      tmp = seg[1];
    }

    ++r;
  }

  printf("%lld\n", res);
  
  return 0;
}
