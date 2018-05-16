#include <bits/stdc++.h>

using namespace std;

set<string> st;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;

  for(char ch = 'a'; ch <= 'z'; ++ch) {
    for(int i = 0; i < s.length(); ++i)
      if(s[i] == ch)
        for(int j = i + 1; j <= i + 1 + 10; ++j)
          st.insert(s.substr(i, j - i));
    if(st.size() >= k)
      break;
  }

  int cnt = 1;
  for(set<string>::iterator it = st.begin(); it != st.end(); ++it, ++cnt)
    if(cnt == k) {
      cout << *it << endl;
      return 0;
    }

  return 0;
}
