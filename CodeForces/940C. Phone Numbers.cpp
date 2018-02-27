#include <bits/stdc++.h>

using namespace std;

int n, k;
bool st[26];
string s;

int main() {
  cin >> n >> k >> s;
  
  for(int i = 0; i < n; ++i)
    st[s[i] - 'a'] = true;

  char sm;
  for(int i = 0; i < 26; ++i)
    if(st[i]) {
      sm = i + 'a';
      break;
    }
  
  if(n < k) {
    cout << s;
    for(int i = 0; i < k - n; ++i)
      cout << sm;
    cout << endl;
    return 0;
  }
  
  if(n > k) {
    int idx;
    char ch = ' ';

    for(int i = k - 1; ch == ' ' && i >= 0; --i)
      for(int j = 0; j < 26; ++j)
        if(st[j] && j > (s[i] - 'a')) {
          idx = i;
          ch = j + 'a';
          break;
        }

    s[idx] = ch;
    for(int i = idx + 1; i < k; ++i)
        s[i] = sm;

    cout << s.substr(0, k) << endl;

    return 0;
  }
  
  int idx;
  char ch = ' ';

  for(int i = n - 1; ch == ' ' && i >= 0; --i)
    for(int j = 0; j < 26; ++j)
      if(st[j] && j > (s[i] - 'a')) {
        idx = i;
        ch = j + 'a';
        break;
      }

  s[idx] = ch;
  for(int i = idx + 1; i < n; ++i)
    s[i] = sm;
  
  cout << s << endl;
  
  return 0;
}
