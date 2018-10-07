#include <bits/stdc++.h>

int t;
long long p[20], n, x;

using namespace std;
int main() {
  p[0] = 1;
  for(int i = 1; i < 20; ++i)
    p[i] = p[i - 1] * 10;

  scanf("%d", &t);
  long long res;
  while(t--) {
    scanf("%lld %lld", &n, &x);
    int cur = floor(log10(x)) + 1;
    res = 0;
    while(true) {
      long long need = p[cur] - x;
      x = p[cur];
      if(need * cur <= n)
        n -= need * cur, res += need, ++cur;
      else {
        res += n / cur;
        n %= cur;
        break;
      }
    }

    if(n != 0) {
      puts("-1");
      continue;
    }

    printf("%lld\n", res);
  }

  return 0;
}
