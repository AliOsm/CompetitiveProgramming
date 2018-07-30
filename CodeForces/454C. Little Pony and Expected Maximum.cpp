/*
  Idea:
    - Solution equal to: sum(((i/m)^n - ((i-1)/m)^n) * i)
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int m, n;
long long a[N];

int main() {
  scanf("%d %d", &m, &n);

  double res = 0;
  for(int i = 1; i <= m; ++i)
    res += (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n)) * i;

  printf("%0.10lf\n", res);

  return 0;
}
