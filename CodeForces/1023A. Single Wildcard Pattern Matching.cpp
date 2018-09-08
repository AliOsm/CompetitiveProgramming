/*
  Idea:
    - Implementation.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
string s, t;

int main() {
  cin >> n >> m;
  cin >> s >> t;

  int w = -1;
  for(int i = 0; i < s.length(); ++i)
    if(s[i] == '*') {
      w = i;
      break;
    }

  if(w == -1 && s != t) {
    puts("NO");
    return 0;
  } else if(w == -1 && s == t) {
    puts("YES");
    return 0;
  }

  if(s.length() - 1 == t.length()) {
    if(w != -1) {
      s.erase(s.begin() + w);
      if(s == t)
        puts("YES");
      else
        puts("NO");
      return 0;
    }

    puts("NO");
    return 0;
  }

  if(s.length() > t.length()) {
    puts("NO");
    return 0;
  }

  for(int i = 0; i < w; ++i)
    if(s[i] != t[i]) {
      puts("NO");
      return 0;
    }

  int need = t.length() - s.length() + 1;
  for(int j = w + 1, i = w + need; i < t.length(); ++i, ++j) {
    if(s[j] != t[i]) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");

  return 0;
}
