#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int k, l, m, n, d, res;

int main() {
  scanf("%d\n%d\n%d\n%d\n%d", &k, &l, &m, &n, &d);
  
  res = 0;
  for(int i = 1; i <= d; ++i)
    res += (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0);
  printf("%d\n", res);
  
  return 0;
}

