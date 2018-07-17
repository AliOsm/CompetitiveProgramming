/*
  Idea:
    - Longest increasing subsequence.
    - Sort the two arrays based on the first one and find the LIS
      in the seconds array, it is the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int k, n, t[N];
pair<int, int> a[N];

int main() {
  scanf("%d", &k);
  while(k-- != 0) {
    memset(t, 0, sizeof t);

    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
      scanf("%d", &a[i].first);
    for(int i = 0; i < n; ++i)
      scanf("%d", &a[i].second);

    sort(a, a + n);

    int l = 0;
    t[0] = a[0].second;

    for(int i = 0, idx; i < n; ++i) {
      idx = upper_bound(t, t + l, a[i].second) - t;
      t[idx] = a[i].second;
      if(idx == l)
        ++l;
    }

    printf("%d\n", l);
  }

  return 0;
}
