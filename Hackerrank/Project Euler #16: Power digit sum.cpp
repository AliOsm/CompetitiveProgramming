#include <bits/stdc++.h>

using namespace std;

int t, n, a[5000], res[10001];

int mul() {
  int carry = 0, ret = 0;
  for(int i = 0; i < 5000; ++i) {
    int res = 2 * a[i] + carry;
    a[i] = res % 10;
    res /= 10;
    carry = res;
    ret += a[i];
  }
  return ret;
}

int main() {
  a[0] = 1;
  for(int i = 1; i <= 10000; ++i)
    res[i] = mul();

  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d", &n);
    printf("%d\n", res[n]);
  }

  return 0;
}
