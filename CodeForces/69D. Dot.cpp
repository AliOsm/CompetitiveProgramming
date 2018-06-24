/*
  Idea:
    - Using DP with state:
      (x, y): the current point position,
      reflect1: is player 1 reflect or not,
      reflect2: is player 2 reflect or not,
      player: who is the current player,
      and for each player try to play the optimal move.
*/

#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

int x, y, n, d;
short dp[651][651][2][2][2];
pair<int, int> points[21];

int dist(int x, int y) {
  return pow(x, 2.0) + pow(y, 2.0);
}

bool rec(int x, int y, bool reflect1, bool reflect2, bool cur) {
  if(dist(x, y) > d)
    return !cur;

  short &ret = dp[x + 200][y + 200][reflect1][reflect2][cur];
  if(ret != -1)
    return ret;
  ret = 0;

  int cnt = 0;
  if(cur == 0) {
    for(int i = 0; i < n; ++i)
      cnt += rec(x + points[i].F, y + points[i].S, reflect1, reflect2, !cur);
    if(!reflect1)
      cnt += rec(y, x, 1, reflect2, !cur);

    if(cnt > 0)
      ret = 1;
    else
      ret = 0;
  } else {
    for(int i = 0; i < n; ++i)
      cnt += !rec(x + points[i].F, y + points[i].S, reflect1, reflect2, !cur);
    if(!reflect2)
      cnt += !rec(y, x, reflect1, 1, !cur);

    if(cnt > 0)
      ret = 0;
    else
      ret = 1;
  }

  return ret;
}

int main() {
  scanf("%d %d %d %d", &x, &y, &n, &d);
  d *= d;

  for(int i = 0; i < n; ++i)
    scanf("%d %d", &points[i].F, &points[i].S);
  
  memset(dp, -1, sizeof dp);
  if(rec(x, y, 0, 0, 0))
    puts("Anton");
  else
    puts("Dasha");

  return 0;
}
