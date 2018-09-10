/*
  Idea:
    - Implementation.
*/

#include <bits/stdc++.h>

using namespace std;

int T, n;
string s;

int main() {
  cin >> T;
  while(T-- != 0) {
    cin >> n >> s;
    bool ok = true;
    for(int i = 0, j = n - 1; i < j; ++i, --j)
      if(s[i] != s[j] && abs(s[i] - s[j]) != 2)
        ok = false;
    if(ok)
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}
