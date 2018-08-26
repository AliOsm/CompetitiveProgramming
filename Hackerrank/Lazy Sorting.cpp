/*
  - Idea:
    - If the array if sorted then the expected value is 0.
    - Otherwise declare fr_i to be the frequency of the i_th element
      in the array, so we can sort the array in `all` = (fr_1! * fr_2! * ... * fr_n!)
      ways, then the probability to sort the array after shuffling is `all/N!`,
      finally the expected value if `1/(all/N!)` which is equal to `N!/all`.
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[18], b[18], fr[101];

long long fact(int x) {
  long long ret = 1;
  for(int i = 2; i <= x; ++i)
    ret *= i;
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), b[i] = a[i], ++fr[a[i]];

  sort(b, b + n);

  bool ok = true;
  for(int i = 0; i < n; ++i)
    if(a[i] != b[i])
      ok = false;

  if(ok) {
    puts("0");
    return 0;
  }

  long long all = fact(n);

  for(int i = 0; i <= 100; ++i)
    all /= fact(fr[i]);

  printf("%lld\n", all);

  return 0;
}
