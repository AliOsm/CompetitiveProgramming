/*
  Idea:
    - Brute force.
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
string t, s;

int main() {
  cin >> n >> k >> t;

  for(int cnt = 0, l = 1; cnt < k; ++cnt) {
    bool ok = true;
    int i, j = 0;

    for(; l < s.length(); ++l) {
      ok = true;
      for(i = l, j = 0; i < s.length() && j < t.length(); ++i, ++j)
        if(s[i] != t[j]) {
          ok = false;
          break;
        }

      if(ok)
        break;
    }

    for(int i = j; i < t.length(); ++i)
      s += t[i];

    l = s.length() - t.length() + 1;
  }

  cout << s << endl;

  return 0;
}
