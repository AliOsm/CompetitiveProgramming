#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, a[N];

int get_min() {
  int ret = -1, mn = 1e9;
  for(int i = 0; i < n; ++i)
    if(mn > a[i])
      mn = a[i], ret = i;
  return ret;
}

int get_max() {
  int ret = -1, mx = -1;
  for(int i = 0; i < n; ++i)
    if(a[i] > mx)
      mx = a[i], ret = i;
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  for(int i = 0, mn, mx; i < 100000; ++i) {
    mn = get_min();
    mx = get_max();
    if(mn != mx)
      a[mx] -= a[mn];
  }

  int sum = 0;
  for(int i = 0; i < n; ++i)
    sum += a[i];

  printf("%d\n", sum);

  return 0;
}
