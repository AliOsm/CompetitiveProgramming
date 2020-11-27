#include <bits/stdc++.h>

using namespace std;

int x, k, n;

int main() {
  scanf("%d %d %d", &x, &k, &n);

  int f = (x / k) * k + k;
  
  bool ok = false;
  for(int i = f; i <= n; i += k) {
    ok = true;
    printf("%d ", i - x);
  }

  if(!ok)
    puts("-1");

  return 0;
}
