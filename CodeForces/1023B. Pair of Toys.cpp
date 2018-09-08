/*
  Idea:
    - Math.
*/

#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() {
  scanf("%lld %lld", &n, &k);
  
  if(k - 1 > n) {
    long long a = k / 2, b = k / 2 + 1;
    if(a <= n && b <= n && a + b == k)
      printf("%lld\n", min(n - b + 1, a));
    else if(a - 1 <= n && a - 1 >= 1 && b <= n && (a - 1) + b == k) {
      --a;
      printf("%lld\n", min(n - b + 1, a));
    } else
      puts("0");
    return 0;
  }

  long long a = 1, b = k - 1;
  long long res = b / 2;
  printf("%lld\n", res);

  return 0;
}
