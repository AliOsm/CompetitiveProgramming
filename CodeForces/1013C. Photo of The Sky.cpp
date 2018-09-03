/*
  Idea:
    - Greedy.
    - Sort the array `a`, then use each `n` consecutive numbers
      as x-axis value and the remaining numbers as y-axis values
      and minimize the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, a[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < 2 * n; ++i)
    scanf("%d", a + i);
  sort(a, a + 2 * n);

  long long res = 1ll * (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);

  for(int i = 1, j = n; i < n; ++i, ++j)
    res = min(res, 1ll * (a[2 * n - 1] - a[0]) * (a[j] - a[i]));

  printf("%lld\n", res);

  return 0;
}
