#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  if(s.length() < 26) {
  	cout << -1 << endl;
  	return 0;
  }

  bool vis[26] = { 0 };

  char cur = 'a';
  for(int i = 0; i < s.length(); ++i) {
  	if(s[i] <= cur) {
  		s[i] = cur;
  		++cur;
  		vis[cur - 'a' - 1] = true;

  		if(cur > 'z')
  			break;

  		continue;
  	}
  }

  for(int i = 0; i < 26; ++i)
  	if(!vis[i]) {
  		cout << -1 << endl;
  		return 0;
  	}

  cout << s << endl;

  return 0;
}
