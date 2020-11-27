#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;

  int mid;
  for(int i = 0; i < s.length(); ++i)
    if(s[i] == '^')
      mid = i;

  bool seen = false;
  long long l = 0, r = 0;
  for(int i = 0; i < s.length(); ++i) {
    if(s[i] == '^')
      seen = true;
    if(isdigit(s[i])) {
      if(!seen)
        l += 1ll * (mid - i) * (s[i] - '0');
      else
        r += 1ll * (i - mid) * (s[i] - '0');
    }
  }

  if(l == r)
    puts("balance");
  else if(l > r)
    puts("left");
  else
    puts("right");

  return 0;
}
