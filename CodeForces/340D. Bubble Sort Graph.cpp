#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N], len, l[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  
  l[0] = a[0];
  len = 1;
  for(int i = 1; i < n; ++i) {
    if(a[i] < l[0])
      l[0] = a[i];
    else if(a[i] > l[len - 1])
      l[len++] = a[i];
    else
      l[lower_bound(l, l + len, a[i]) - l] = a[i];
  }

  printf("%d\n", len);

  return 0;
}
