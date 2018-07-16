#include <bits/stdc++.h>

using namespace std;

int n;
string s[301];
set<int> s1, s2;

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> s[i];
  
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(i == j || (i + j) == s[0].length() - 1)
        s1.insert(s[i][j]);
      else
        s2.insert(s[i][j]);
    }
  }

  if(s1.size() == 1 && s2.size() == 1 && *s1.begin() != *s2.begin())
    puts("YES");
  else
    puts("NO");

  return 0;
}
