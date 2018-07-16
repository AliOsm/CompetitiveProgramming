#include <bits/stdc++.h>

using namespace std;

int const N = 201;
int n, a[N], b[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d %d", a + i, b + i);
  
  int res = 0;
  for(int i = 0; i < n; ++i) {
    bool u, r, d, l;
    u = r = d = l = false;

    for(int j = 0; j < n; ++j) {
      if(a[i] == a[j] && b[i] < b[j])
        u = true;
      if(a[i] < a[j] && b[i] == b[j])
        r = true;
      if(a[i] == a[j] && b[i] > b[j])
        d = true;
      if(a[i] > a[j] && b[i] == b[j])
        l = true;
    }

    res += (u + r + d + l) == 4;
  }

  printf("%d\n", res);

  return 0;
}
