/*
  Idea:
    - Brute force.
    - Try to remove each switch i and compute the total number of
      lamps turned on.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, fr[2001];
string s[2001];

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    cin >> s[i];
    for(int j = 0; j < m; ++j)
      fr[j] += (s[i][j] - '0');
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j)
      fr[j] -= (s[i][j] - '0');
    bool ok = true;
    for(int j = 0; j < m; ++j)
      if(fr[j] == 0) {
        ok = false;
        break;
      }
    if(ok) {
      puts("YES");
      return 0;
    }
    for(int j = 0; j < m; ++j)
      fr[j] += (s[i][j] - '0');
  }

  puts("NO");

  return 0;
}
