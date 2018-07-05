#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, x;
  cin >> a >> b >> x;

  string s;
  if(a > b)
    s = "0", --a;
  else
    s = "1", --b;

  for(int i = 0; i < x; ++i) {
    if(b > 0 && s.back() == '0')
      --b, s += '1';
    else if(a > 0)
      --a, s += '0';
  }

  for(int i = 0; i < s.length(); ++i) {
    cout << s[i];
    if(a > 0 && s[i] == '0')
      while(a-- != 0)
        cout << '0';
    if(b > 0 && s[i] == '1')
      while(b-- != 0)
        cout << '1';
  }
  cout << endl;

  return 0;
}
