/*
  idea:
    - We can try every possible possibility and count the number of win states
      for each possibility, then choose the one with the greatest number of
      win states.
*/

#include <bits/stdc++.h>

using namespace std;

class QuizShow {
  int wager(vector<int> scores, int wager1, int wager2) {
    int best = 0, cnt, ret = 0;
    for(int wager0 = 0; wager0 <= scores[0]; ++wager0) {
      cnt = 0;
      for(int i = -1; i <= 1; i += 2)
        for(int j = -1; j <= 1; j += 2)
          for(int k = -1; k <= 1; k += 2)
            if(scores[0] + i * wager0 > scores[1] + j * wager1 &&
               scores[0] + i * wager0 > scores[2] + k * wager2)
              ++cnt;
      if(cnt > best)
        best = cnt, ret = wager0;
    }

    return ret;
  }
}
