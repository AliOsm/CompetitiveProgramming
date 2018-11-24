/*
  Idea:
    - Math
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  scanf("%d %d", &n, &k);

  int r = n * 2;
  int g = n * 5;
  int b = n * 8;

  int res = ceil(1.0 * r / k) + ceil(1.0 * g / k) + ceil(1.0 * b / k);

  printf("%d\n", res);

  return 0;
}
