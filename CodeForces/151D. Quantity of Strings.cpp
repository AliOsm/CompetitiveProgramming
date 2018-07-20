/*
  Idea:
    - If n equal to k then there is (m ^ ((n + 1) / 2)) strings
    - If n < k or k = 1 then there is (m ^ n) strings
    - If k is even there is (m) strings
    - Otherwise there is (m ^ 2) strings
*/

#include <bits/stdc++.h>

using namespace std;

int const M = 1e9 + 7;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);

  long long res;

  if(n == k) {
    res = 1;
    for(int i = 0; i < (n + 1) / 2; ++i)
      res *= m,
      res %= M;
  } else if(k > n || k == 1) {
    res = 1;
    for(int i = 0; i < n; ++i)
      res *= m,
      res %= M;
  } else if(k % 2 == 0)
    res = m;
  else
    res = m * m;

  printf("%lld\n", res);

  return 0;
}
