/*
  Idea:
    - Greedy.
    - Check all differences (between `x` and `y`) and cross
      the same differences with different signes and if
      there is more negative values, then print `No`,
      otherwise print `Yes`.
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[51], b[51], d[51];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0; i < n; ++i)
    scanf("%d", b + i);
  for(int i = 0; i < n; ++i)
    d[i] = a[i] - b[i];

  for(int k = 0; k < 10000; ++k) {
    for(int i = 0; i < n; ++i) {
      if(d[i] <= 0)
        continue;
      for(int j = 0; j < n; ++j)
        if(d[j] < 0 && d[i] > 0)
          d[i] += d[j], d[j] = 0;
      break;
    }
  }

  bool ok = true;
  for(int i = 0; i < n; ++i)
    if(d[i] < 0)
      ok = false;

  if(ok)
    puts("Yes");
  else
    puts("No");

  return 0;
}
