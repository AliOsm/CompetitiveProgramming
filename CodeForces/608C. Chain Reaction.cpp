/*
  Idea:
    - Dynamic Programming.
    - dp[i] represent the number of alive beacons until ith one and the new
      beacon in the right will kill all beacons after the ith one.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int n, dp[N], b[N];

int main() {
  scanf("%d", &n);
  for(int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    scanf("%d", b + a);
  }

  int res = 0;
  dp[0] = b[0] != 0;
  for(int i = 1; i < N; ++i) {
    if(b[i] == 0)
      dp[i] = dp[i - 1];
    else {
      if(b[i] >= i)
        dp[i] = 1;
      else
        dp[i] = dp[i - b[i] - 1] + 1;
    }

    res = max(res, dp[i]);
  }

  printf("%d\n", n - res);

  return 0;
}
