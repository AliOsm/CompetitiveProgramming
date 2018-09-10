#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  s += s;

  int res = 0;
  for(int i = 0; i < s.length(); ++i) {
    int cur = 1;
    while(i + 1 < s.length() && s[i] != s[i + 1] && cur < s.length() / 2)
      ++cur, ++i;
    res = max(res, cur);
  }

  printf("%d\n", res);

  return 0;
}
