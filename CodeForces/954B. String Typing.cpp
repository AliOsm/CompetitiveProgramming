/*
	Idea:
		- Brute force, try to find the longest duplicated prefix.
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
  cin >> n >> s;
  
  int mx = 0;
  for(int i = 1; i <= n; ++i) {
  	string tmp = s.substr(0, i);
		if(tmp == s.substr(i, i))
			mx = tmp.size();
  }

  cout << (mx > 0) + (n - mx) << endl;

  return 0;
}
