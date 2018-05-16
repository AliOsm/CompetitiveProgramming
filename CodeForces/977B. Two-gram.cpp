#include <bits/stdc++.h>

using namespace std;

int n, best, cur;
string s, res;

int main() {
  cin >> n >> s;

  for(char c1 = 'A'; c1 <= 'Z'; ++c1)
    for(char c2 = 'A'; c2 <= 'Z'; ++c2) {
      cur = 0;
      for(int i = 1; i < n; ++i)
        cur += (c1 == s[i-1] && c2 == s[i]);
      if(cur > best) {
        best = cur;
        res = "";
        res += c1;
        res += c2;
      }
    }

  cout << res << endl;

  return 0;
}
