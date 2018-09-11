/*
  Idea:
    - Using coordinate compression and cumulative sum
      we can determine if there is a solution greater than
      0 or not.
    - If there is a solution, then calculate it and keep
      track the segments that effect this solution at the end.
    - Finally, try to remove each segment of the last 2 segments
      effected the solution and maximize the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;
int n, a[N], b[N], aa[N], bb[N], cs[2 * N + 100];
vector<int> all;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
    all.push_back(a[i]);
    all.push_back(b[i]);
  }

  if(n == 2) {
    printf("%d\n", max(b[0] - a[0], b[1] - a[1]));
    return 0;
  }

  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());

  for(int i = 0; i < n; ++i) {
    aa[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
    bb[i] = lower_bound(all.begin(), all.end(), b[i]) - all.begin();
  }

  for(int i = 0; i < n; ++i) {
    cs[aa[i]] += 1;
    cs[bb[i] + 1] += -1;
  }

  int cur = 0;
  for(int i = 0; i < 2 * N + 100; ++i) {
    cur += cs[i];
    cs[i] = cur;
  }

  int mx = -1;
  for(int i = 0; i < 2 * N + 100; ++i)
    mx = max(mx, cs[i]);

  if(mx < n - 1) {
    puts("0");
    return 0;
  }

  int l = a[0], r = b[0], ex[2] = {0, 0};
  for(int i = 1; i < n; ++i) {
    if(a[i] >= l && a[i] <= r)
      l = a[i], ex[0] = i;
    if(b[i] >= l && b[i] <= r)
      r = b[i], ex[1] = i;
  }

  int res = -1;
  for(int j = 0, l, r; j < 2; ++j) {
    if(ex[j] == 0)
      l = a[1], r = b[1];
    else
      l = a[0], r = b[0];

    for(int i = 0; i < n; ++i) {
      if(i == ex[j])
        continue;
      if(a[i] >= l && a[i] <= r)
        l = a[i];
      if(b[i] >= l && b[i] <= r)
        r = b[i];
    }
    res = max(res, r - l);
  }

  printf("%d\n", res);

  return 0;
}
