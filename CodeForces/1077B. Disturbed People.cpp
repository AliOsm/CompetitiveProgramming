#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, a[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  int res = 0;
  for(int i = 1; i < n - 1; ++i)
    if(a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1)
      a[i + 1] = 0, ++res;

  printf("%d\n", res);

  return 0;
}
