#include <bits/stdc++.h>

using namespace std;

int t, a, b, k;

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d %d %d", &a, &b, &k);

    int aa = (k + 1) / 2;
    int bb = k / 2;

    long long res = 1ll * a * aa - 1ll * b * bb;
    printf("%lld\n", res);
  }

  return 0;
}
