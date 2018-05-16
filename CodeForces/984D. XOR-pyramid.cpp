#include <bits/stdc++.h>

using namespace std;

int const N = 5001;
int n, q, l, r, a[N], dp[N][N], sol[N][N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    dp[0][i] = sol[0][i] = a[i];
  }

  for(int i = 1; i < n; ++i)
    for(int j = 0; j < n - i; ++j)
      dp[i][j] = dp[i - 1][j] ^ dp[i - 1][j + 1],
      sol[i][j] = max(dp[i][j], max(sol[i - 1][j], sol[i - 1][j + 1]));

  scanf("%d", &q);
  for(int i = 0; i < q; ++i) {
    scanf("%d %d", &l, &r);
    --l, --r;
    printf("%d\n", sol[r - l][l]);
  }

  return 0;
}
