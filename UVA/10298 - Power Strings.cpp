#include <iostream>
#include <string>

using namespace std;

int const N = 1e6 + 1;
int f[N];

void kmpWork(string &s) {
  int i = 1, j = 0;
  while(i < s.length()) {
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) ++j;
    f[i++] = j;
  }
}

int main() {
  string s;
  
  int res;
  while(cin >> s && s != ".") {
    kmpWork(s);
    
    res = s.length();
    if(s.length() % (s.length() - f[s.length() -1]) == 0)
      res = s.length() - f[s.length() - 1];
    
    cout << s.length() / res << endl;
  }
  
  return 0;
}

