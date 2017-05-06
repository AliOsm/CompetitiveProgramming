#include <iostream>
#include <string>

using namespace std;

int const N = 81;
int f[N];

void kmpWork(string const &s) {
  int i = 1, j = 0;
  while(i < s.length()) {
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) ++j;
    f[i++] = j;
  }
}

int main() {
  bool blankline = false;
  
  int t;
  cin >> t;
  
  string s;
  int res;
  while(t-- != 0) {
    if(blankline)
      cout << endl;
    cin >> s;
    kmpWork(s);
    res = s.length();
    if(s.length() % (s.length() - f[s.length() - 1]) == 0)
      res = s.length() - f[s.length() - 1];
    cout << res << endl;
    blankline = true;
  }
  
  return 0;
}

