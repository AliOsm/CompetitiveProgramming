/*
  Idea:
    - Dynamic Programming.
    - dp[sum][rem][cur]:
      `sum` represents the current money we have.
      `rem` represents the remaining rounds we have.
      `cur` represents the number of rounds we had lose.
    - In each step we calculate the summation of the probability
      of winning or lossing the current round.
*/

#include <bits/stdc++.h>

using namespace std;

double dp[1001][51][51];

class TestBettingStrategy {
  double rec(int sum, int rem, int cur, int &gol, double prb) {
    if(sum >= gol)
      return 1;
    if(sum <= 0 || rem <= 0 || pow(2, cur) > sum)
      return 0;

    double &ret = dp[sum][rem][cur];
    if(ret == ret)
      return ret;
    ret = 0;

    return ret = prb * rec(sum + pow(2, cur), rem - 1, 0, gol, prb) +
                 (1.0 - prb) * rec(sum - pow(2, cur), rem - 1, cur + 1, gol, prb);
  }

public:
  double winProbability(int initSum, int goalSum, int rounds, int prob) {
    memset(dp, -1, sizeof dp);
    return rec(initSum, rounds, 0, goalSum, 1.0 * prob / 100.0);
  }
};
