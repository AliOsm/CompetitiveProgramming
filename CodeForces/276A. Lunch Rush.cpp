#include <bits/stdc++.h>

using namespace std;

int n, k, f, t;

int main() {
  scanf("%d %d", &n, &k);
  int res = -2e9;
  while(n-- != 0) {
    scanf("%d %d", &f, &t);
    if(t > k)
      res = max(res, f - (t - k));
    else
      res = max(res, f);
  }
  if(res == -2e9)
    puts("-1");
  else
    printf("%d\n", res);
  
  return 0;
}
