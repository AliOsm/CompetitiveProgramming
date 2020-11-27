#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, m, a[N], pos, neg, l, r;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    if(a[i] == 1)
      ++pos;
    else
      ++neg;
  }

  for(int i = 0; i < m; ++i) {
    scanf("%d %d", &l, &r);
    int diff = r - l + 1;
    if(diff % 2 == 1)
      puts("0");
    else {
      if(diff / 2 <= pos && diff / 2 <= neg)
        puts("1");
      else
        puts("0");
    }
  }

  return 0;
}
