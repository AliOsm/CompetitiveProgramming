#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, k[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", k + i);
  
  int res = 1e9;
  for(int i = 0; i < n; ++i) {
    int cur = 0;
    for(int j = 0, tmp; j < k[i]; ++j) {
      scanf("%d", &tmp);
      cur += 5 * tmp + 15;
    }
    res = min(res, cur);
  }

  printf("%d\n", res);

  return 0;
}
