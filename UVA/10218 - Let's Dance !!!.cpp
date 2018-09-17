/*
  Idea:
    - Dynamic Programming.
    - dp[men][rem]:
      `men` represents the number of the gentle men take candies till now.
      `rem` represents the number of remaining candies.
    - In each step calculate the probability of give the current candy
      to a gentle men or to a woman and sum the probabilities.
*/

#include <bits/stdc++.h>

using namespace std;

int m, w, c;
double dp[1000][100];

double rec(int men, int rem) {
  if(rem == 0)
    return men % 2 == 0;

  double &ret = dp[men][rem];
  if(ret == ret)
    return ret;
  ret = 0;

  return ret = 1.0 * m / (m + w) * rec(men + 1, rem - 1) + 1.0 * w / (m + w) * rec(men, rem - 1);
}

int main() {
  while(scanf("%d %d %d", &m, &w, &c) && (m != 0 || w != 0)) {
    memset(dp, -1, sizeof dp);
    printf("%0.7lf\n", rec(0, c));
  }

  return 0;
}
