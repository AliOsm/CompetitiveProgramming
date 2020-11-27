#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  scanf("%d %d", &n, &k);

  int div = k / n;
  int rem = k % n;

  if(div == 2)
    printf("%d\n", n - rem);
  else
    printf("%d\n", 0);

  return 0;
}
