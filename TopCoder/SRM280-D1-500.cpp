/*
  Idea:
    - Try to build the maximum full square starting from (0, 0).
    - Then the answer is this square plus:
      (1 full row or column + 1 non-ful row or column)
      or
      (1 non-ful row or column)
    - Brute force to find the maximum full square.
*/

#include <bits/stdc++.h>

using namespace std;

class GridCut {
  int solve(int width, int height, int n) {
    int r1 = 0, r2 = 0;
    
    if(width * height == n)
      return 0;
    
    if(width > height)
      swap(width, height);

    int rem = n % width;
    
    if(n > width * height - width)
      r1 = width - rem + 1;
    else if(rem == 0)
      r1 = width;
    else
      r1 = width + 1;

    int mx = 0;
    for(int i = 1; i <= width; ++i)
      if(n >= i * i)
        mx = i;

    int tmp = n;
    n -= mx * mx;

    if(mx == width) {
      n %= width;
      if(tmp > width * height - width)
        r2 = width - n + 1;
      else if(n == 0)
        r2 = width;
      else
        r2 = width + 1;
    } else {
      int plus = n >= mx;
      if(plus)
        n -= mx;
      n = max(0, n);

      if(mx + plus == width) {
        if(mx + 1 == height) {
          if(n == 0) {
            r2 = width;
          } else {
            r2 = width - n + 1;
          }
        } else {
          r2 = width + 1;
        }
      } else {
        if(n == 0)
          r2 = mx + (mx + plus);
        else
          r2 = mx + (mx + plus) + 1;
      }
    }

    return min(r1, r2);
  }
  
public:
  int cutLength(int width, int height, int n) {
    return min(solve(width, height, n), solve(width, height, width * height - n));
  }
};
