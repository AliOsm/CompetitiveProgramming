/*
  Idea:
    - The optimal move of Masha is to remove the first `1` from the left.
    - The optimal move of Petya is to remove the first `0` from the left.
    - Set `g` to the number of games (string length / 2).
    - We can observe that if we want the end result to be `00`, then we need
      the string to have at least `g + 2` zeros and at most `g` ones.
    - Also, we can observe that is we want the end result to be `11`, then we
      need the string to have at most `g` zeros and at least `g + 2` ones.
    - For the case of `01` and `10` we need the string to have exactly
      `g + 1` zeros and `g + 1` ones and either end with `1` for `01` case
      and end with `0` for `10` case or end with `?` for the both cases.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
char s[N];

int main() {
  scanf("%s", s);
  int len = strlen(s);

  int zc = 0, oc = 0, qc, zcn, ocn, g = len - 2;
  for(int i = 0; i < len; ++i)
    zc += s[i] == '0', oc += s[i] == '1';
  qc = len - (zc + oc);

  // 00
  zcn = g / 2 - zc + 2; // petya
  ocn = ceil(g / 2.0) - oc; // masha
  if(zcn < 0) zcn = 0;
  if(ocn < 0) ocn = 0;
  if(zcn <= 0 || zcn + ocn == qc)
    puts("00");

  // 01
  zcn = g / 2 - zc + 1; // petya
  ocn = ceil(g / 2.0) - oc + 1; // masha
  if(zcn < 0) zcn = 0;
  if(ocn < 0) ocn = 0;
  if((zcn <= 0 && ocn <= 0 || zcn + ocn == qc) && s[len - 1] == '1')
    puts("01");
  else if(s[len - 1] == '?') {
    zcn = g / 2 - zc + 1; // petya
    ocn = ceil(g / 2.0) - oc; // masha

    if(zcn < 0) zcn = 0;
    if(ocn < 0) ocn = 0;
    if(zcn <= 0 && ocn <= 0 || zcn + ocn == qc - 1)
      puts("01");
  }

  // 10
  zcn = g / 2 - zc + 1; // petya
  ocn = ceil(g / 2.0) - oc + 1; // masha
  if(zcn < 0) zcn = 0;
  if(ocn < 0) ocn = 0;
  if((zcn <= 0 && ocn <= 0 || zcn + ocn == qc) && s[len - 1] == '0')
    puts("10");
  else if(s[len - 1] == '?') {
    zcn = g / 2 - zc; // petya
    ocn = ceil(g / 2.0) - oc + 1; // masha

    if(zcn < 0) zcn = 0;
    if(ocn < 0) ocn = 0;
    if(zcn <= 0 && ocn <= 0 || zcn + ocn == qc - 1)
      puts("10");
  }

  // 11
  zcn = g / 2 - zc; // petya
  ocn = ceil(g / 2.0) - oc + 2; // masha
  if(zcn < 0) zcn = 0;
  if(ocn < 0) ocn = 0;
  if(ocn <= 0 || zcn + ocn == qc)
    puts("11");

  return 0;
}
