/*
  Idea:
    - Build next array for string `a`, then using it iterate over string `b`
      and each time try to find the current character `b[i]`, if you cannot
      find it then return to the beginning of the string `a` and try to find
      it again.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int k = 1, nxt[N][26];
bool vis[26];
string a, b;

int main() {
  cin >> a >> b;
  
  for(int i = 0; i < a.length(); ++i)
    vis[a[i] - 'a'] = true;
  for(int i = 0; i < b.length(); ++i)
    if(!vis[b[i] - 'a']) {
      cout << -1 << endl;
      return 0;
    }
  
  memset(nxt, -1, sizeof nxt);
  for(int i = a.length() - 2; i >= 0; --i) {
    for(int j = 0; j < 26; ++j)
      nxt[i][j] = nxt[i + 1][j];
    nxt[i][a[i + 1] - 'a'] = i + 1;
  }
  
  for(int i = 0, whr = -1; i < b.length(); ++i) {
    char cur = b[i];
    
    if(whr == -1) {
      if(a[0] == cur)
        whr = 0;
      else
        whr = nxt[0][cur - 'a'];
    } else {
      if(nxt[whr][cur - 'a'] != -1)
        whr = nxt[whr][cur - 'a'];
      else
        whr = -1, ++k, --i;
    }
  }
  
  cout << k << endl;
  
  return 0;
}
