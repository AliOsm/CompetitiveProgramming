/*
  Idea:
    - If `k` equal 1 then the probability is 0.
    - Otherwise if `k` is odd then the probability is
      the summation of odd numbers from 1 to `k - 2`
      divided by `n * (n - 1) / 2`, else if `k` is even
      then the probability is the summation of even numbers
      from 1 to `k - 2` divided by `n * (n - 1) / 2`.
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  while(scanf("%d %d", &n, &k) && n != -1 && k != -1) {
    if(k == 1)
      puts("0");
    else {
      k -= 2;

      long long sum = 1ll * k * (k + 1) / 2;

      if(k & 1) {
        k /= 2;
        sum -= 1ll * k * (k + 1) / 2 * 2;
      } else {
        k /= 2;
        sum = 1ll * k * (k + 1) / 2 * 2;
      }

      long long all = 1ll * n * (n - 1) / 2;
      long long gcd = __gcd(sum, all);

      if(sum == 0) {
        puts("0");
        continue;
      }

      if(sum == all) {
        puts("1");
        continue;
      }

      printf("%lld/%lld\n", sum / gcd, all / gcd);
    }
  }

  return 0;
}
