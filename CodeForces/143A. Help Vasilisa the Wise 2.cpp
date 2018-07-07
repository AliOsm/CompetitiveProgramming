/*
  Idea:
    - Brute force.
    - Try to find any sorted subset of numbers between 1 and 9 inclusive
      contains exactly 4 number.
    - Try any permutation of this subset of numbers, if any of them give you
      an answer then print it and exit.
*/

#include <bits/stdc++.h>

using namespace std;

int r1, r2, c1, c2, d1, d2;
vector<int> all, tmp;

void rec(int idx) {
  if(idx > 10)
    return;

  if(all.size() == 4) {
    tmp = all;
    do {
      bool ok = true;

      if(tmp[0] + tmp[1] != r1)
        ok = false;
      if(tmp[2] + tmp[3] != r2)
        ok = false;
      if(tmp[0] + tmp[2] != c1)
        ok = false;
      if(tmp[1] + tmp[3] != c2)
        ok = false;
      if(tmp[0] + tmp[3] != d1)
        ok = false;
      if(tmp[1] + tmp[2] != d2)
        ok = false;

      if(ok) {
        cout << tmp[0] << ' ' << tmp[1] << endl;
        cout << tmp[2] << ' ' << tmp[3] << endl;
        exit(0);
      }
    } while(next_permutation(tmp.begin(), tmp.end()));
    return;
  }

  rec(idx + 1);

  all.push_back(idx);
  rec(idx + 1);
  all.pop_back();
}

int main() {
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

  rec(1);
  cout << -1 << endl;

  return 0;
}
