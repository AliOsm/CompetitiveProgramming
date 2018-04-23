#include <bits/stdc++.h>

using namespace std;

int const N = 3e5;
int n, a[N];
vector<vector<int> > seg;

void build(int idx, int l, int r) {
  if(l == r) {
    seg[idx].push_back(a[l]);
    return;
  }

  int mid = (l + r) / 2;
  build(idx * 2, l, mid);
  build(idx * 2 + 1, mid + 1, r);

  int i, j;
  for(i = 0, j = 0; i < seg[idx * 2].size() && j < seg[idx * 2 + 1].size();)
    if(seg[idx * 2][i] <= seg[idx * 2 + 1][j])
      seg[idx].push_back(seg[idx * 2][i++]);
    else
      seg[idx].push_back(seg[idx * 2 + 1][j++]);

  if(i != seg[idx * 2].size()) {
    for(; i < seg[idx * 2].size(); ++i)
      seg[idx].push_back(seg[idx * 2][i]);
  }

  if(j != seg[idx * 2 + 1].size()) {
    for(; j < seg[idx * 2 + 1].size(); ++j)
      seg[idx].push_back(seg[idx * 2 + 1][j]);
  }
}

int s, e, val;
long long get(int idx, int l, int r) {
  if(l > e || r < s)
    return 0;

  if(l >= s && r <= e) {
    int id = lower_bound(seg[idx].begin(), seg[idx].end(), val) - seg[idx].begin();
    return max(int(seg[idx].size()) - id, 0);
  }

  int mid = (l + r) / 2;
  return get(idx * 2, l, mid) + get(idx * 2 + 1, mid + 1, r);
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
  	scanf("%d", a + i);

  seg.resize(4 * N);
  build(1, 1, n);

  long long res = 0;
  for(int i = 1; i < n; ++i) {
  	s = i + 1, e = s + (a[i] - i - 1), val = i;
  	if(e > n)
  		e = n;
  	if(e < s)
  		continue;
  	res += max(get(1, 1, n), 0ll);
  }

  printf("%lld\n", res);

  return 0;
}
