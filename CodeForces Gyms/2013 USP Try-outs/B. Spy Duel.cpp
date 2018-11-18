/*
  Idea:
    - Precalculate the probability of getting damage `d`
      from each attack, this can be done by calculating
      the probability using brute force.
    - Then using dynamic programming we can calculate the
      probability of `A` to win.
    - dp[rema][remb][p] represents:
      - rema: the remaining health of `A`
      - remb: the remaining health of `B`
      - p: the current player
    - In each turn in the dp we try all attacks using
      all possible damages.
*/

#include <bits/stdc++.h>

using namespace std;

int t, va, vb, na, nb, a[3];
double prop[2][10][37], dp[301][301][2];
vector<int> dd[2];

void input(int n, int p) {
  for(int i = 0, d; i < n; ++i) {
    scanf("%d", &d);
    a[0] = a[1] = a[2] = 0;
    for(int i = 0; i < d; ++i)
      scanf("%d", a + i);
    dd[p].push_back(a[0] + a[1] + a[2]);
    
    if(d == 1) {
      for(int j = 1; j <= a[0]; ++j)
        prop[p][i][j] = 1.0 / a[0];
    } else if(d == 2) {
      for(int j = 1; j <= a[0]; ++j)
        for(int k = 1; k <= a[1]; ++k)
          prop[p][i][j + k] += 1.0 / (a[0] * a[1]);
    } else {
      for(int j = 1; j <= a[0]; ++j)
        for(int k = 1; k <= a[1]; ++k)
          for(int l = 1; l <= a[2]; ++l)
          prop[p][i][j + k + l] += 1.0 / (a[0] * a[1] * a[2]);
    }
  }
}

double rec(int rema, int remb, int p) {
  if(rema <= 0)
    return 0;
  if(remb <= 0)
    return 1;
  
  double &ret = dp[rema][remb][p];
  if(ret == ret)
    return ret;
  ret = p;

  for(int i = 0; i < dd[p].size(); ++i) {
    double tmp = 0;
    for(int j = 1; j <= dd[p][i]; ++j)
      tmp += prop[p][i][j] * rec(!p ? rema : (rema - j), p ? remb : (remb - j), !p);
    
    if(p)
      ret = min(ret, tmp);
    else
      ret = max(ret, tmp);
  }

  return ret;
}

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d %d %d %d", &va, &vb, &na, &nb);

    memset(prop, 0, sizeof prop);
    dd[0].clear();
    dd[1].clear();
    input(na, 0);
    input(nb, 1);

    memset(dp, -1, sizeof dp);
    printf("%.10lf\n", rec(va, vb, 0));
  }

  return 0;
}
