#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s, rev;
  cin >> s;
  
  for(int i = 0; i < s.length(); i++) {
    char tmp = s[i];
    for(char ch = 'a'; ch <= 'z'; ch++) {
      s[i] = ch;
      rev = s;
      reverse(rev.begin(), rev.end());
      if(ch != tmp && s == rev) {
        cout << "YES" << endl;
        return 0;
      }
    }
    s[i] = tmp;
  }
  
  cout << "NO" << endl;
  
  return 0;
}
