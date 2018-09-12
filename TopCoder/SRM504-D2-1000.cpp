/*
  Idea:
    - Brute force.
    - Starting from the first row in the `output` grid, try all
      possible strings contains `W`s and `B`s only and check
      if you can apply the algorithm using the current row
      on the generated one and get the next row, then the generated
      row it is the row in the input grid.
*/

#include <bits/stdc++.h>

using namespace std;

class Algrid {
public:
  vector<string> makeProgram(vector<string> output) {
    vector<string> ret;
    ret.resize(output.size());
    ret[0] = output[0];

    for(int i = 0; i < output.size() - 1; ++i) {
      for(int msk = (1 << output[i].length()) - 1; msk >= -1; --msk) {
        if(msk == -1) {
          vector<string> ret;
          return ret;
        }

        string s = "";
        for(int j = output[i].length() - 1; j >= 0; --j)
          s += ((msk >> j) & 1) ? 'B' : 'W';
        string ss = s;

        for(int j = 0; j < output[i].length() - 1; ++j) {
          if(output[i][j] == 'B' && output[i][j + 1] == 'W')
            s[j] = s[j + 1] = 'B';
          if(output[i][j] == 'W' && output[i][j + 1] == 'B')
            s[j] = s[j + 1] = 'W';
          if(output[i][j] == 'B' && output[i][j + 1] == 'B')
            swap(s[j], s[j + 1]);
        }

        if(s == output[i + 1]) {
          ret[i + 1] = ss;
          break;
        }
      }
    }

    return ret;
  }
};
