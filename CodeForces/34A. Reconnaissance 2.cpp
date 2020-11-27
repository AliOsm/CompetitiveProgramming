#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, a[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  
  int mn = 1e9 + 1, k, l;
  for(int i = 0; i < n; ++i)
    if(abs(a[i] - a[(i + 1) % n]) < mn) {
      mn = abs(a[i] - a[(i + 1) % n]);
      k = i;
      l = (i + 1) % n;
    }
  
  printf("%d %d\n", k + 1, l + 1);

  return 0;
}
