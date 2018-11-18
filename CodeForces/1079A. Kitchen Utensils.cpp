/*
  Idea:
    - Search for the minimum number of dishes where the needed
      utensils greater than the current ones.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, k, fr[N], fr1[N];

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0, tmp; i < n; ++i) {
    scanf("%d", &tmp);
    ++fr[tmp];
  }

  int res = 0;
  for(int d = 1; d <= 100; ++d) {
    memset(fr1, 0, sizeof fr1);
    for(int i = 1; i <= 100; ++i)
      if(fr[i] != 0)
        fr1[i] = k * d;
    bool ok = true;
    for(int i = 1; i <= 100; ++i) {
      if(fr1[i] < fr[i]) {
        ok = false;
        break;
      }
    }
    if(ok) {
      for(int i = 1; i <= 100; ++i)
        res += fr1[i] - fr[i];
      break;
    }
  }

  printf("%d\n", res);

  return 0;
}
