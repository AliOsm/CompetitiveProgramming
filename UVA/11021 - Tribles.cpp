/*
  Idea:
    - We can solve this problem using Dynamic Programming.
    - dp[i] represents the probability of all Tribles are die in the ith day.
    - We can calculate the probability of one Trible and raise it to the power
      of the number of Tribles we have.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int t, n, k, m;
double a[N], dp[N];

double rec(int gen) {
  if(gen == m)
    return 0;

  double &ret = dp[gen];
  if(ret == ret)
    return ret;
  ret = a[0];

  for(int i = 1; i < n; ++i)
    ret += a[i] * pow(rec(gen + 1), i);

  return ret;
}

int main() {
  int kase = 1;
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < n; ++i)
      scanf("%lf", a + i);

    memset(dp, -1, sizeof dp);
    printf("Case #%d: %.10lf\n", kase++, pow(rec(0), k));
  }

  return 0;
}
