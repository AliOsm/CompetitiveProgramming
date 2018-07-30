#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, p, a[N][4];

int main() {
  scanf("%d %d", &n, &p);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i][0], &a[i][1]);
    a[i][2] = a[i][1] - a[i][0] + 1;
    a[i][3] = a[i][1] / p - (a[i][0] - 1) / p;
  }
  a[n][2] = a[0][2];
  a[n][3] = a[0][3];

  double res = 0;
  for(int i = 0; i < n; ++i)
    res += 1 - 1.0 * (a[i][2] - a[i][3]) / a[i][2] * (a[i + 1][2] - a[i + 1][3]) / a[i + 1][2];

  printf("%0.10lf\n", res * 2000);

  return 0;
}
