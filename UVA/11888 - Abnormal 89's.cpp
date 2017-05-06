#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int const N = 1e6 + 1;
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
  int t;
  cin >> t;
  
  string s, tmp, rev, s1, s2, revs1, revs2;
  bool allSame;
  while(t-- != 0) {
    cin >> s;
    tmp = s;
    
    allSame = true;
    
    for(int i = 0; i < s.length() - 1; ++i) 
      if(s[i] != s[i + 1]) {
        allSame = false;
        break;
      }
    
    if(allSame && s.length() > 1) {
      cout << "alindrome" << endl;
      continue;
    }
    
    if(s.length() == 1) {
      cout << "palindrome" << endl;
      continue;
    }
    
    rev = s;
    reverse(rev.begin(), rev.end());
    
    s = tmp + '@' + rev;
    kmpWork(s);
    
    s1 = tmp.substr(0, f[s.length() - 1]);
    revs1 = s1;
    reverse(revs1.begin(), revs1.end());
    
    s2 = tmp.substr(f[s.length() - 1]);
    revs2 = s2;
    reverse(revs2.begin(), revs2.end());
    
    if(!s1.empty() && !s2.empty() && s1 == revs1 && s2 == revs2) {
      cout << "alindrome" << endl;
      continue;
    }
    
    s1 = rev.substr(0, f[s.length() - 1]);
    revs1 = s1;
    reverse(revs1.begin(), revs1.end());
    
    s2 = rev.substr(f[s.length() - 1]);
    revs2 = s2;
    reverse(revs2.begin(), revs2.end());
    
    if(!s1.empty() && !s2.empty() && s1 == revs1 && s2 == revs2) {
      cout << "alindrome" << endl;
      continue;
    }
    
    s = rev + '@' + tmp;
    kmpWork(s);
    
    s1 = tmp.substr(0, f[s.length() - 1]);
    revs1 = s1;
    reverse(revs1.begin(), revs1.end());
    
    s2 = tmp.substr(f[s.length() - 1]);
    revs2 = s2;
    reverse(revs2.begin(), revs2.end());
    
    if(!s1.empty() && !s2.empty() && s1 == revs1 && s2 == revs2) {
      cout << "alindrome" << endl;
      continue;
    }
    
    s1 = rev.substr(0, f[s.length() - 1]);
    revs1 = s1;
    reverse(revs1.begin(), revs1.end());
    
    s2 = rev.substr(f[s.length() - 1]);
    revs2 = s2;
    reverse(revs2.begin(), revs2.end());
    
    if(!s1.empty() && !s2.empty() && s1 == revs1 && s2 == revs2) {
      cout << "alindrome" << endl;
      continue;
    }
    
    s1 = tmp.substr(0, tmp.length() / 2);
    s2 = tmp.substr(tmp.length() / 2);
    
    if(s1 == s2) {
      cout << "alindrome" << endl;
      continue;
    }
    
    if(rev == tmp) {
      cout << "palindrome" << endl;
      continue;
    }
    
    cout << "simple" << endl;
  }
  
  return 0;
}

