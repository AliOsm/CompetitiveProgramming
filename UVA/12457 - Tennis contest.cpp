/*
  Idea:
    - Dynamic programming.
    - `idx` represents the number of the games played till now.
    - `win` represents the number of the games winned till now.
    - In each step try to win the current game with probability
      `p` and loss the current game with probability `1 - p`.
*/

#include <bits/stdc++.h>

using namespace std;

int t, n;
double p, dp[55][55];

double calc(int idx, int win) {
  if(idx == 2 * n - 1) {
    if(win >= n)
      return 1;
    else
      return 0;
  }

  double &ret = dp[idx][win];
  if(ret == ret)
    return ret;
  ret = 0;

  ret += p * calc(idx + 1, win + 1);
  ret += (1 - p) * calc(idx + 1, win);

  return ret;
}

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d\n%lf", &n, &p);
    memset(dp, -1, sizeof dp);
    printf("%0.2lf\n", calc(0, 0));
  }

  return 0;
}
