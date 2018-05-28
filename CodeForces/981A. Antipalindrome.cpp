/*
	Idea:
		- Brute force, try every possible substring.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int mx = 0;
  for(int i = 0; i < s.length(); ++i) {
  	for(int j = 1; j <= s.length(); ++j) {
  		string tmp = s.substr(i, j), rev = tmp;
  		reverse(rev.begin(), rev.end());
  		if(tmp != rev)
  			mx = max(mx, int(tmp.length()));
  	}
  }

  cout << mx << endl;

  return 0;
}
