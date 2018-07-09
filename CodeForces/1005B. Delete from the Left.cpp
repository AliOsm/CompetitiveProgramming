#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int res = 0;
  for(int i = s.length() - 1, j = t.length() - 1; i >= 0 && j >= 0; --i, --j)
    if(s[i] == t[j])
      ++res;
    else
      break;

  cout << (s.length() - res) + (t.length() - res) << endl;

  return 0;
}
