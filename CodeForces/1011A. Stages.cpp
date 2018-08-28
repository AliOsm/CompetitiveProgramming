/*
  Idea:
    - Implementation.
*/

#include <bits/stdc++.h>

using namespace std;

int k, fr[26];
string s;

int main() {
  int n;
  cin >> n >> k >> s;

  for(int i = 0; i < s.length(); ++i)
    ++fr[s[i] - 'a'];

  int best = 1e9;
  for(int i = 0; i < 26; ++i) {
    int cur = 0, cost = 0, j = i;
    while(j < 26) {
      if(cur == k)
        break;
      if(fr[j] != 0)
        ++cur, cost += (j + 1), j += 2;
      else
        ++j;
    }
    if(cur == k && cost < best)
      best = cost;
  }

  if(best == 1e9) {
    cout << -1 << endl;
    return 0;
  }
  cout << best << endl;

  return 0;
}
