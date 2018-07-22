/*
  Idea:
    - GREEDY.
    - If all elements in the same set or the minimum in one
      set and the other elements in the same set.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, h, sol[N];
pair<int, int> a[N];

int main() {
  scanf("%d %d", &n, &h);
  for(int i = 0; i < n; ++i)
    scanf("%d", &a[i].first), a[i].second = i;
  sort(a, a + n);

  int r1 = (a[n - 1].first + a[n - 2].first) - (a[0].first + a[1].first);
  int r2 = max(a[0].first + a[n - 1].first + h, a[n - 1].first + a[n - 2].first) - min(a[0].first + a[1].first + h, a[1].first + a[2].first);

  if(r1 < r2) {
    printf("%d\n", r1);
    for(int i = 0; i < n; ++i)
      sol[a[i].second] = 1;
  } else {
    printf("%d\n", r2);
    sol[a[0].second] = 1;
    for(int i = 1; i < n; ++i)
      sol[a[i].second] = 2;
  }

  for(int i = 0; i < n; ++i)
    printf("%s%d", i == 0 ? "" : " ", sol[i]);
  puts("");

  return 0;
}
