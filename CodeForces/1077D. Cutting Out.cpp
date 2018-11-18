#include <bits/stdc++.h>

using namespace std;

int const N = 4e5 + 10;
int n, k, a[N];
pair<int, int> fr[N];

bool can(int mid) {
  int with = 0;
  for(int i = 0; i < N; ++i)
    if(with >= k)
      return true;
    else
      with += fr[i].first / mid;
  return with >= k;
}

int main() {
  for(int i = 0; i < N; ++i)
    fr[i].second = i;

  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), ++fr[a[i]].first;

  sort(fr, fr + N);
  reverse(fr, fr + N);

  int l = 1, r = 1e9, res = 0, mid;
  while(l <= r) {
    mid = (l + r) >> 1;
    if(can(mid))
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }

  int cnt = 0;
  for(int i = 0; cnt < k && i < N; ++i) {
    for(int j = 0, to = fr[i].first / res; cnt < k && j < to; ++j)
      printf("%d ", fr[i].second), ++cnt;
  }
  puts("");

  return 0;
}
