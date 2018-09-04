/*
  idea:
    - http://codeforces.com/blog/entry/61015
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;
int n, a[2][N];
long long s[2], fr[2][N], bk[2][N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < n; ++j)
      scanf("%d", &a[i][j]), s[i] += a[i][j];

  for(int i = 0; i < 2; ++i)
    for(int j = n - 1; j >= 0; --j)
      fr[i][j] = fr[i][j + 1] + 1ll * j * a[i][j],
      bk[i][j] = bk[i][j + 1] + 1ll * (n - j - 1) * a[i][j];

  long long res = fr[0][0] + bk[1][0] + s[1] * n, cur = 0;
  int row = 0, col = 0, pro = 0;
  for(int i = 0; i < 2 * n; ++i) {
    long long tmp = fr[row][col] + 1ll * s[row] * (i - col) + bk[!row][col + pro] + 1ll * s[!row] * (i + n - col);
    res = max(res, cur + tmp);

    cur += 1ll * i * a[row][col];
    s[row] -= a[row][col];

    if(pro == 0)
      row = !row;
    else
      ++col;

    pro = !pro;
  }

  printf("%lld\n", res);

  return 0;
}
