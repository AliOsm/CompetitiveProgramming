/*
  Idea:
    - The answer is `n` choose 3, but there is points on the same line, so the area is 0.
    - To count the number of points on the same line we can use line slope with GCD, so we do not use doubles.
    - To avoid overlapping we can start searching for points on the same line from the next point from the current one.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2001;
int n, a[N], b[N], dp[N][N];
map<pair<int, int>, int> mp;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d %d", a + i, b + i);
  
  for(int i = 0; i < N; ++i)
    for(int j = 0; j <= i; ++j)
      if(i == 0 || i == j)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
  
  int res = dp[n][3];

  for(int i = 0; i < n; ++i) {
    mp.clear();
    for(int j = i + 1, x, y, gcd; j < n; ++j) {
      x = a[j] - a[i];
      y = b[j] - b[i];

      gcd = __gcd(x, y);
      x /= gcd;
      y /= gcd;

      ++mp[{x, y}];
    }

    for(map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
      int cur = it->second;
      if(cur >= 2)
        res -= dp[cur][2];
    }
  }

  printf("%d\n", max(0, res));

  return 0;
}
