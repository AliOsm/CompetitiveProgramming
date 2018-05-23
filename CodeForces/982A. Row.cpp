/*
  Idea:
    - Brute force.
    - Try to put 1 in each index i if and only if s[i] equal to 0 and check the
      string.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  if(n == 1) {
  	if(s == "0")
  		cout << "NO" << endl;
  	else
  		cout << "YES" << endl;
  	return 0;
  }

  if(n == 2) {
  	if(s == "00" || s == "11")
  		cout << "NO" << endl;
  	else
  		cout << "YES" << endl;
  	return 0;
  }

  for(int j = 1; j < n; ++j)
		if(s[j] == s[j-1] && s[j] == '1') {
			cout << "No" << endl;
			return 0;
		}

  for(int i = 0; i < n; ++i) {
  	if(s[i] == '0') {
  		s[i] = '1';
  		bool ok = true;
  		for(int j = 1; j < n; ++j)
  			if(s[j] == s[j-1] && s[j] == '1') {
  				ok = false;
  				break;
  			}
  		s[i] = '0';
  		if(ok) {
  			cout << "No" << endl;
  			return 0;
  		}
  	}
  }

  cout << "Yes" << endl;

  return 0;
}
