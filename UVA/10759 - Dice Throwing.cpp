/*
  Idea:
    - The output is (the number of correct states) divided by
      (the number of all states).
    - It is easy to count the number of all states, it is equal to
      `6^n`, becuase we have `n` dices and each one has 6 outputs.
    - To count the number of correct states we can start a DP and
      take the number of dices we had thrown and the current sum.
*/

#include <bits/stdc++.h>

using namespace std;

int n, x;
unsigned long long dp[24][145];

unsigned long long rec(int idx, int sum) {
  if(idx == n)
    return sum >= x;

  unsigned long long &ret = dp[idx][sum];
  if(ret != ULLONG_MAX)
    return ret;
  ret = 0;

  for(int i = 1; i <= 6; ++i)
    ret += rec(idx + 1, sum + i);

  return ret;
}

int main() {
  while(scanf("%d %d", &n, &x) && (n != 0 || x != 0)) {
    for(int i = 0; i < 24; ++i)
      for(int j = 0; j < 145; ++j)
        dp[i][j] = ULLONG_MAX;

    unsigned long long res = rec(0, 0);
    unsigned long long all = pow(6, n);

    unsigned long long gcd = __gcd(res, all);

    if(res == 0) {
      puts("0");
      continue;
    }

    if(res == all) {
      puts("1");
      continue;
    }

    printf("%llu/%llu\n", res / gcd, all / gcd);
  }

  return 0;
}
