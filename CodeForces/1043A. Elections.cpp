#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n, a[N];

int main() {
  int mx = -1, t = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), t += a[i], mx = max(mx, a[i]);

  for(int i = mx; i < 10000; ++i) {
    int cur = 0;
    for(int j = 0; j < n; ++j) {
      cur += i - a[j];
    }

    if(cur > t) {
      printf("%d\n", i);
      return 0;
    }
  }

  return 0;
}
