/*
  Idea:
    - Simple implementation.
    - Try to apply the rules to the given string.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int idx = s.find('.');
  if(idx == string::npos)
    s += ".00";
  while(idx != string::npos && s.length() - 1 - idx > 2)
    s.pop_back();
  if(idx != string::npos && s.length() - 1 - idx == 1)
    s += "0";

  idx = s.find('.');
  int rem = 0;
  if(s[0] == '-')
    rem = idx - 1;
  else
    rem = idx;

  while(rem > 0) {
    idx -= 3, rem -= 3;
    if(idx <= 0)
      continue;
    if(idx == 1 && s[0] == '-')
      continue;
    s.insert(idx, ",");
  }

  if(s[0] == '-')
    cout << "($" << s.substr(1) << ')' << endl;
  else
    cout << '$' << s << endl;

  return 0;
}
