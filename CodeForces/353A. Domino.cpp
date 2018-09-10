#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, s[2], a[N], b[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
    s[0] += a[i];
    s[1] += b[i];
  }

  if(s[0] % 2 == 0 && s[1] % 2 == 0) {
    puts("0");
  } else if(s[0] % 2 == 1 && s[1] % 2 == 1) {
    for(int i = 0; i < n; ++i)
      if(a[i] % 2 == 0 && b[i] % 2 == 1) {
        puts("1");
        return 0;
      } else if(a[i] % 2 == 1 && b[i] % 2 == 0) {
        puts("1");
        return 0;
      }
    puts("-1");
  } else {
    puts("-1");
  }

  return 0;
}
