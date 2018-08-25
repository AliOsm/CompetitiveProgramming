/*
  Idea:
    - We can solve this problem using DP.
    - In each step in the DP try to take each door using its prbability.
    - If the door takes you outside, then add its hours * its probability
      to the result, otherwise if the door bring you back add its hours *
      its probability and go from it to new recursion call, but the multiply
      the returned value with the current door probability.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int t, n, x[N];
double p[N], dp[N * N];

double rec(int cur) {
  if(cur > N * N)
    return 0;

  double &ret = dp[cur];
  if(ret == ret)
    return ret;
  ret = 0;

  for(int i = 0; i < n; ++i)
    if(x[i] > 0)
      ret += 1.0 * x[i] * p[i];
    else {
      ret += 1.0 * -x[i] * p[i] + p[i] * rec(cur + 1);
    }

  return ret;
}

int main() {
  int kase = 0;
  scanf("%d", &t);
  while(t-- != 0) {
    memset(dp, -1, sizeof dp);

    bool ok = false;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
      scanf("%d %lf", x + i, p + i);
      if(x[i] > 0)
        ok = true;
    }

    if(!ok)
      printf("Case %d: God! Save me\n", ++kase);
    else
      printf("Case %d: %.2lf\n", ++kase, rec(0));
  }

  return 0;
}
