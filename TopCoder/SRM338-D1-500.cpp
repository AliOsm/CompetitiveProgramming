/*
  Idea:
    - Dynamic programming.
    - dp[cnt][eql]:
      `cnt` represents the number of swaps finished till now.
      `eql` represents if we are in the final place or not.
    - In each step we calculate two possibilities, the first one if
      we will stay in the same place or we go to another one.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
double dp[N][2];

class RandomSwaps {
  double rec(int cnt, bool eql, int const &Cnt, int const nn, int const &al) {
    if(cnt == Cnt) {
      if(eql)
        return 1;
      return 0;
    }

    double &ret = dp[cnt][eql];
    if(ret == ret)
      return ret;
    ret = 0;

    if(eql)
      ret = (1.0 * (nn - (al - 1)) / nn) * rec(cnt + 1, true, Cnt, nn, al) +
            (1.0 * (al - 1) / nn) * rec(cnt + 1, false, Cnt, nn, al);
    else
      ret = (1.0 / nn) * rec(cnt + 1, true, Cnt, nn, al) +
            (1.0 * (nn - 1) / nn) * rec(cnt + 1, false, Cnt, nn, al);

    return ret;
  }

public:
  double getProbability(int arrayLength, int swapCount, int a, int b) {
    memset(dp, -1, sizeof dp);
    return rec(0, a == b, swapCount, arrayLength * (arrayLength - 1) / 2, arrayLength);
  }
};
