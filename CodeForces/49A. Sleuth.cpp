#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  getline(cin, s);
  
  for(int i = s.length() - 1; i >= 0; --i) {
    if(isalpha(s[i])) {
      s[i] = tolower(s[i]);
      string v = "aioeuy";
      if(v.find(s[i]) != string::npos)
        puts("YES");
      else
        puts("NO");
      return 0;
    }
  }

  return 0;
}
