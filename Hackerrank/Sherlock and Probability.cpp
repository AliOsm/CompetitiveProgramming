/*
  Idea:
    - Using cumulative sum we can know how many ones in front
      of me.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
char s[N];
int t, n, k, len, cs[N];

int main() {
  scanf("%d", &t);
  for(int i = 0; i < t; ++i) {
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    len = strlen(s);

    for(int j = 1; j <= len; ++j)
      cs[j] = cs[j - 1] + (s[j - 1] == '1');

    long long res = 0;
    for(int j = 0; j < len; ++j)
      if(s[j] == '1') {
        int ones = cs[min(len, j + k + 1)] - cs[j];
        res += (ones - 1) * 2 + 1;
      }

    long long all = 1ll * n * n;
    long long gcd = __gcd(res, all);

    printf("%lld/%lld\n", res / gcd, all / gcd);
  }

  return 0;
}
