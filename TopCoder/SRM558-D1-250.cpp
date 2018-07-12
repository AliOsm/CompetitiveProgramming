/*
  Idea:
    - Brute forcing the length `L`.
    - Each time choosing `L` go and check if the desiredColor string can
      be splitted in the minimum number of segments.
    - If you can't return a huge value.
    - If you can't continue with the current segment with length `L`,
      try to complete it using some characters from the previous one.
    - Recursively you can solve the problems in the segments to allow
      the current one to take the characters it is need from the previous
      segment.
*/

#include <string>

using namespace std;

class Stamp {
public:
  int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
    long long ret = 2e18;
    for(int L = 1; L <= desiredColor.length(); ++L)
      ret = min(ret, 1ll * pushCost * check(L, desiredColor) + 1ll * stampCost * L);
    return ret;
  }

  int check(int L, string desiredColor) {
    char all[desiredColor.length()];
    for(int i = 0; i < desiredColor.length(); ++i)
      all[i] = ' ';

    int cnt = 0;
    for(int i = 0; i < desiredColor.length();) {
      char ch = ' ';
      int j;

      for(j = i; j < i + L; ++j) {
        if(ch != ' ' && desiredColor[j] != ch && desiredColor[j] != '*')
          break;

        if(ch == ' ' && desiredColor[j] != '*')
          ch = desiredColor[j];

        if(ch != ' ')
          all[j] = ch;
      }

      if(j == i + L) {
        i += L, ++cnt;
        continue;
      }

      int tmp = j;

      int need = (i + L) - j, s = i - need;
      if(s < 0)
        return 1e9;

      for(j = i - 1; j >= s; --j) {
        if(ch != ' ' && all[j] != ' ' && all[j] != ch)
          if(!solve(L, desiredColor, j, all))
            return 1e9;

        if(ch != ' ' && desiredColor[j] != ch && desiredColor[j] != '*')
          return 1e9;

        if(ch == ' ' && desiredColor[j] != '*')
          ch = desiredColor[j];

        if(ch != ' ')
          all[j] = ch;
      }
      
      i = tmp, ++cnt;
    }
    
    return cnt;
  }

  bool solve(int L, string desiredColor, int j, char all[]) {
    if(j - L < 0)
      return false;

    char ch = ' ';
    if(desiredColor[j] != '*')
      ch = desiredColor[j];

    for(int k = j - 1; k >= j - L; --k) {
      if(all[k] != ' ' && ch != ' ' && all[k] != ch)
        if(!solve(L, desiredColor, k, all))
          return false;

      if(ch != ' ' && desiredColor[k] != ch && desiredColor[k] != '*')
        return false;

      if(ch == ' ' && desiredColor[k] != '*')
        ch = desiredColor[k];

      if(ch != ' ')
        all[k] = ch;
    }

    return true;
  }
};
