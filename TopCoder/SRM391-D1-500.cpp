/*
  Idea:
    - https://community.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm391
*/

#include <bits/stdc++.h>

using namespace std;

long long str[21][21], fact[21];

class KeysInBoxes {
public:
  string getAllKeys(int N, int M) {
    str[0][0] = 1;
    for(int i = 1; i < 21; ++i)
      for(int j = 0; j <= i; ++j)
        str[i][j] = str[i - 1][j - 1] + i * str[i - 1][j];

    fact[0] = 1;
    for(int i = 1; i < 21; ++i)
      fact[i] = fact[i - 1] * i;

    long long res = 0;
    for(int i = 0; i < M; ++i)
      res += str[N - 1][i];

    long long gcd = __gcd(res, fact[N]);

    return to_string(res / gcd) + "/" + to_string(fact[N] / gcd);
  }
};
