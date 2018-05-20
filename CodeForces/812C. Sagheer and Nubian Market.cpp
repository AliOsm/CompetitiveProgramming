/*
  Idea:
    - binary search on the maximum value of `k`
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;
int n, s, a[N];
long long b[N];

bool can(int mid) {
  for(int i = 0; i < n; ++i)
    b[i] = 1ll * a[i] + 1ll * (i + 1) * mid;
  sort(b, b + n);
  long long tot = 0;
  for(int i = 0; i < mid; ++i) {
    if(tot > s)
      return false;
    tot += b[i];
  }
  return tot <= s;
}

int main() {
  scanf("%d %d", &n, &s);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  int l = 0, r = n, res = -1, mid;
  while(l <= r) {
    mid = (l + r) / 2;
    if(can(mid)) {
      l = mid + 1;
      res = mid;
    } else
      r = mid - 1;
  }

  if(res == 0)
    puts("0 0");
  else {
    can(res);
    long long tot = 0;
    for(int i = 0; i < res; ++i)
      tot += b[i];
    printf("%d %lld\n", res, tot);
  }

  return 0;
}
