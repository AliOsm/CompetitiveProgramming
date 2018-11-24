/*
  Idea:
    - Calculate white and black squares in the (n, m) rectangle
    - Do the first query:
      Calculate the white and black squares in the first
      rectangle, then update the original ones
    - Do the second query:
      Calculate the white and black squares in the second
      rectangle, check for the intersection, then update
      the original ones
*/

#include <bits/stdc++.h>

using namespace std;

int t, n, m;
int x, y, x2, y2;
int xx, yy, xx2, yy2;
int xxx, yyy, xxx2, yyy2;

int FindPoints() { 
  xxx = max(x, xx);
  yyy = max(y, yy);

  xxx2 = min(x2, xx2);
  yyy2 = min(y2, yy2);

  if(xxx > xxx2 || yyy > yyy2)
    return 0;

  return 1;
}

void calcWB(int x, int y, int x2, int y2, long long &w, long long &b) {
  int dx = abs(x2 - x + 1);
  int dy = abs(y2 - y + 1);

  if(x % 2 == 1 && y % 2 == 1 || x % 2 == 0 && y % 2 == 0) {
    if(dx % 2 == 0) {
      w = 1ll * dx / 2 * dy;
      b = 1ll * dx * dy - w;
    } else {
      w = 1ll * ((dx + 1) / 2) * ((dy + 1) / 2) + 1ll * (dx / 2) * (dy / 2);
      b = 1ll * dx * dy - w;
    }
  } else {
    if(dx % 2 == 0) {
      b = 1ll * dx / 2.0 * dy;
      w = 1ll * dx * dy - b;
    } else {
      b = 1ll * ((dx + 1) / 2) * ((dy + 1) / 2) + 1ll * (dx / 2) * (dy / 2);
      w = 1ll * dx * dy - b;
    }
  }
}

int main() {
  scanf("%d", &t);
  for(int i = 0; i < t; ++i) {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &x, &y, &x2, &y2);
    scanf("%d %d %d %d", &xx, &yy, &xx2, &yy2);

    // calculate all
    long long w, b;
    calcWB(1, 1, m, n, w, b);

    // first query
    long long w1, b1;
    calcWB(x, y, x2, y2, w1, b1);

    // update
    b -= b1;
    w += b1;

    // second query
    long long w2, b2;
    calcWB(xx, yy, xx2, yy2, w2, b2);

    // check intersection
    if(FindPoints() == 1) {
      long long ww, bb;
      calcWB(xxx, yyy, xxx2, yyy2, ww, bb);

      b2 -= bb;
      w2 += bb;
    }

    // update
    b += w2;
    w -= w2;

    printf("%lld %lld\n", w, b);
  }

  return 0;
}
